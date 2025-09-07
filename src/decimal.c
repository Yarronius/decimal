#include "decimal.h"

// Main functions
int add(decimal value_1, decimal value_2, decimal *result) {
  int code = 0;
  int sgn1 = (int)get_sign(value_1);
  int sgn2 = (int)get_sign(value_2);

  int scl1 = get_scale(value_1);
  int scl2 = get_scale(value_2);

  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  int signs_not_eq = (sgn1 + sgn2) % 2;

  if (signs_not_eq) {
    decimal tmp1 = sgn1 == 0 ? value_1 : value_2;
    decimal tmp2 = sgn2 == 0 ? value_1 : value_2;

    code = sub(tmp1, tmp2, result);
    sgn1 = is_less(tmp1, tmp2) ? 1 : 0;

  } else {
    big_decimal tmp_r;
    big_decimal tmp1 = decimal_to_big(value_1);
    big_decimal tmp2 = decimal_to_big(value_2);
    normalize_big(&tmp1, &tmp2, &scl1, &scl2);
    bigdecimal_add(tmp1, tmp2, &tmp_r);

    if (tmp_r.bits[5] || tmp_r.bits[4] || tmp_r.bits[3]) {
      code = reduce_scale(&tmp_r, &scl1);
    }
    *result = big_to_decimal(tmp_r);
    set_scale(result, scl1);
  }

  set_sign(result, sgn1);
  if (sgn1 + sgn2 == 2 && code == 1) code++;

  return code;
}

int sub(decimal value_1, decimal value_2, decimal *result) {
  int code = 0;
  unsigned int sgn1 = get_sign(value_1);
  unsigned int sgn2 = get_sign(value_2);
  int scl1 = get_scale(value_1);
  int scl2 = get_scale(value_2);

  set_sign(&value_1, 0);
  set_sign(&value_2, 0);

  big_decimal tmp1 = decimal_to_big(value_1);
  big_decimal tmp2 = decimal_to_big(value_2);
  big_decimal tmp_r;

  normalize_big(&tmp1, &tmp2, &scl1, &scl2);

  if (sgn1 + sgn2 == 1) {
    bigdecimal_add(tmp1, tmp2, &tmp_r);
  } else if (is_less(value_1, value_2)) {
    bigdecimal_sub(tmp2, tmp1, &tmp_r);
    sgn1 = sgn1 == 0 ? 1 : 0;
  } else {
    bigdecimal_sub(tmp1, tmp2, &tmp_r);
  }

  if (tmp_r.bits[5] || tmp_r.bits[4] || tmp_r.bits[3]) {
    code = reduce_scale(&tmp_r, &scl1);
  }
  *result = big_to_decimal(tmp_r);
  set_scale(result, scl1);
  set_sign(result, sgn1);
  return code;
}

int mul(decimal value_1, decimal value_2, decimal *result) {
  int code;
  int r_sgn = ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31)) % 2;

  int scl1 = get_scale(value_1);
  int scl2 = get_scale(value_2);
  int r_scl = scl1 + scl2;

  big_decimal tmp1 = decimal_to_big(value_1);
  big_decimal tmp2 = decimal_to_big(value_2);
  big_decimal tmp_r;

  bigdecimal_mul(tmp1, tmp2, &tmp_r);
  code = reduce_scale(&tmp_r, &r_scl);
  *result = big_to_decimal(tmp_r);
  set_sign(result, r_sgn);
  set_scale(result, r_scl);
  if (r_sgn == 1 && code == 1) code++;

  return code;
}

int div(decimal value_1, decimal value_2, decimal *result) {
  init_by_zeroes(result);
  int code = 0;
  if (decimal_zero(value_2) == 1) {
    code = 3;
  } else if (decimal_zero(value_1) != 1) {
    big_decimal tmp1 = decimal_to_big(value_1);
    big_decimal tmp2 = decimal_to_big(value_2);
    int sgn = ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31)) % 2;

    int scl1 = get_scale(value_1);
    int scl2 = get_scale(value_2);
    int r_scl = scl1 - scl2;

    big_decimal tmp_r, remain;
    while (bigdecimal_is_less(tmp1, tmp2) && r_scl < 28) {
      bigdecimal_mul(tmp1, get_big_decimal_10(), &tmp1);
      r_scl++;
    }

    if (bigdecimal_is_less(tmp1, tmp2) != 1) {
      remain = bigdecimal_div(tmp1, tmp2, &tmp_r);

      while (big_decimal_zero(remain) != 1 && r_scl < 28) {
        bigdecimal_mul(tmp1, get_big_decimal_10(), &tmp1);
        remain = bigdecimal_div(tmp1, tmp2, &tmp_r);
        r_scl++;
      }
      while (r_scl < 0) {
        bigdecimal_mul(tmp_r, get_big_decimal_10(), &tmp_r);
        r_scl++;
      }

      code = reduce_scale(&tmp_r, &r_scl);
      *result = big_to_decimal(tmp_r);
      set_sign(result, sgn);
      set_scale(result, r_scl);
      if (sgn == 1 && code == 1) code++;
    } else if (decimal_zero(value_1) != 1) {
      code = 1;
    }
  }
  return code;
}

int is_less(decimal v1, decimal v2) {
  int arg = FALSE;
  int flag = 0;
  int s1 = (int)get_sign(v1);
  int s2 = (int)get_sign(v2);

  if (s1 && !s2) {
    arg = TRUE;
  } else if (!s1 && s2) {
    arg = FALSE;
  } else {
    big_decimal t1 = decimal_to_big(v1);
    big_decimal t2 = decimal_to_big(v2);
    int scl1 = get_scale(v1);
    int scl2 = get_scale(v2);
    normalize_big(&t1, &t2, &scl1, &scl2);

    for (int i = 5; i >= 0 && !flag; i--) {
      if (t1.bits[i] > t2.bits[i]) {
        arg = FALSE;
        flag = 1;
      } else if (t1.bits[i] < t2.bits[i]) {
        arg = TRUE;
        flag = 1;
      }
    }
    if (s1 && s2) {
      arg = !arg;
    }
  }
  return arg;
}

int is_less_or_equal(decimal v1, decimal v2) {
  return !is_greater(v1, v2);
}

int is_greater(decimal v1, decimal v2) {
  int arg = FALSE;
  int flag = 0;
  int s1 = (int)get_sign(v1);
  int s2 = (int)get_sign(v2);
  if (s1 && !s2) {
    arg = FALSE;
  } else if (!s1 && s2) {
    arg = TRUE;
  } else {
    big_decimal t1 = decimal_to_big(v1);
    big_decimal t2 = decimal_to_big(v2);
    int scl1 = get_scale(v1);
    int scl2 = get_scale(v2);
    normalize_big(&t1, &t2, &scl1, &scl2);

    for (int i = 5; i >= 0 && !flag; i--) {
      if (t1.bits[i] > t2.bits[i]) {
        arg = TRUE;
        flag = 1;
      } else if (t1.bits[i] < t2.bits[i]) {
        arg = FALSE;
        flag = 1;
      }
    }
    if (s1 && s2) {
      arg = !arg;
    }
  }
  return arg;
}

int is_greater_or_equal(decimal v1, decimal v2) {
  return !is_less(v1, v2);
}

int is_equal(decimal v1, decimal v2) {
  int arg = TRUE;
  int s1 = (int)get_sign(v1);
  int s2 = (int)get_sign(v2);
  if (decimal_zero(v1) && decimal_zero(v2)) {
    arg = TRUE;
  } else if (s1 != s2) {
    arg = FALSE;
  } else {
    big_decimal t1 = decimal_to_big(v1);
    big_decimal t2 = decimal_to_big(v2);
    int scl1 = get_scale(v1);
    int scl2 = get_scale(v2);
    normalize_big(&t1, &t2, &scl1, &scl2);

    for (int i = 0; i < 6 && arg != FALSE; ++i) {
      if (t1.bits[i] != t2.bits[i]) {
        arg = FALSE;
      } else {
        arg = TRUE;
      }
    }
  }
  return arg;
}

int is_not_equal(decimal v1, decimal v2) {
  return !is_equal(v1, v2);
}

int from_int_to_decimal(int src, decimal *dst) {
  int error = 0;
  if (dst == NULL) {
    error = 1;
  } else {
    init_by_zeroes(dst);
    int sgn = src < 0 ? 1 : 0;
    src = src < 0 ? src * -1 : src;
    dst->bits[0] = src;
    set_sign(dst, sgn);
  }
  return error;
}

int from_float_to_decimal(float src, decimal *dst) {
  decimal mant, exp, two;
  init_by_zeroes(&mant);
  init_by_zeroes(&exp);
  init_by_zeroes(&two);
  init_by_zeroes(dst);
  two.bits[0] = 2;

  unsigned int allnum = *(unsigned int *)(void *)&src;
  int epart = (allnum << 1 >> 24) - 127;
  exp.bits[0] = 1;

  unsigned int sign = allnum >> 31;
  int mpart = (allnum << 9) >> 9;
  mant.bits[0] = mpart;

  int count = epart < 0 ? epart * -1 : epart;
  int code = 0;
  for (int i = 0; i < count && code == 0; i++) {
    if (epart > 0) {
      code = mul(exp, two, &exp);
    } else {
      code = div(exp, two, &exp);
    }
  }
  if (code == 0) {
    set_bit(&mant, 23, 1);

    for (int i = 0; i < 23; i++) {
      div(mant, two, &mant);
    }
    code = mul(mant, exp, dst);
    reduce_to_7(dst);
    set_sign(dst, sign);
  }
  if (code != 0) init_by_zeroes(dst);
  if (src == 0) code = 0;
  return code == 0 ? 0 : 1;
}

int from_decimal_to_int(decimal src, int *dst) {
  int error = 0;
  int degree = get_scale(src);
  big_decimal temp = decimal_to_big(src);
  if (get_scale(src) > 0) {
    while (degree != 0) {
      bigdecimal_div(temp, get_big_decimal_10(), &temp);
      degree -= 1;
    }
  }

  if (temp.bits[1] || temp.bits[2] || temp.bits[3] || temp.bits[4] ||
      temp.bits[5] || get_big_bit(temp, 31)) {
    error = 1;
  } else {
    *dst = temp.bits[0];
    *dst = get_sign(src) == 0 ? *dst : *dst * -1;
  }

  return error;
}

int from_decimal_to_float(decimal src, float *dst) {
  int code = 0;
  if (decimal_zero(src) != 1) {
    decimal two;
    init_by_zeroes(&two);
    two.bits[0] = 2;
    int sgn = get_sign(src);
    set_sign(&src, 0);

    int e = get_floatexp(src);
    int shifte = e + 127;
    reduce_floatexp(&src, e);

    for (int i = 0; i < 23; i++) {
      mul(src, two, &src);
    }
    int scale = get_scale(src);

    big_decimal bigtmp = decimal_to_big(src);
    int prev_zeroes = TRUE;
    big_decimal remain;
    init_big_by_zeroes(&remain);
    for (int i = 0; i < scale; i++) {
      remain = bigdecimal_div(bigtmp, get_big_decimal_10(), &bigtmp);
      prev_zeroes = big_decimal_zero(remain) ? TRUE : FALSE;
    }
    bank_round(&bigtmp, remain, prev_zeroes);
    src = big_to_decimal(bigtmp);

    unsigned int result = *dst;
    if (last_bit_index(src) > 24) {
      code = 1;
    } else {
      set_bit(&src, 23, 0);
      result = src.bits[0];
      if (sgn == 1) {
        unsigned int l = 1;
        result = result | (l << 31);
      }
      shifte = shifte << 23;
      result = result | shifte;
    }
    *dst = *(float *)(void *)&result;
  } else {
    *dst = 0;
  }
  return code;
}

int floor(decimal value, decimal *result) {
  int error = 0;
  int sign = get_sign(value);

  if (result == NULL) {
    error = 1;
  } else {
    if (value.bits[3] == PLUS || value.bits[3] == MINUS) {
      *result = value;
    } else {
      if (sign == 0) {
        truncate(value, result);
      } else if (sign == 1) {
        int degree = get_scale(value);
        int power_of_ten = pow(10, degree);
        decimal remainder;  // дробная часть
        decimal trunc;      // убрали дробную часть
        decimal unit_for_rounding;
        int unit = -1;
        init_by_zeroes(&remainder);
        init_by_zeroes(&trunc);
        truncate(value, &trunc);
        init_by_zeroes(&unit_for_rounding);
        from_int_to_decimal(unit, &unit_for_rounding);
        sub(value, trunc, &remainder);
        int rest_remainder;
        from_decimal_to_int(remainder, &rest_remainder);
        if (rest_remainder / power_of_ten < 5) {
          add(trunc, unit_for_rounding, result);
        } else {
          *result = trunc;
        }
      }
    }
  }
  return error;
}

int round(decimal value, decimal *result) {
  int error = 0;
  int sign = get_sign(value);

  if (result == NULL) {
    error = 1;
  } else {
    decimal remainder;  // дробная часть
    decimal trunc;      // убрали дробную часть
    int unit = sign == 0 ? 1 : -1;
    decimal unit_for_rounding;
    init_by_zeroes(&remainder);
    init_by_zeroes(&trunc);
    truncate(value, &trunc);
    init_by_zeroes(&unit_for_rounding);
    from_int_to_decimal(unit, &unit_for_rounding);
    sub(value, trunc, &remainder);
    float rest_remainder;
    from_decimal_to_float(remainder, &rest_remainder);
    if (rest_remainder != 0 && (int)(rest_remainder * 10 * unit) >= 5) {
      add(trunc, unit_for_rounding, result);
    } else {
      *result = trunc;
    }
  }
  return error;
}

int truncate(decimal value, decimal *result) {
  int error = 0;
  if (result == NULL) {
    error = 1;
  } else {
    decimal ten_degree;
    big_decimal power_of_ten;
    init_by_zeroes(result);
    init_by_zeroes(&ten_degree);
    init_big_by_zeroes(&power_of_ten);

    power_of_ten.bits[0] = 1;
    int degree = get_scale(value);
    int sgn = get_sign(value);
    if (get_scale(value) > 0) {
      while (degree != 0) {
        bigdecimal_mul(power_of_ten, get_big_decimal_10(),
                           &power_of_ten);
        degree -= 1;
      }
      big_decimal temp = decimal_to_big(value);
      bigdecimal_div(temp, power_of_ten, &temp);
      *result = big_to_decimal(temp);
      set_sign(result, sgn);
    } else {
      *result = value;
    }
  }
  return error;
}

int negate(decimal value, decimal *result) {
  int error = 0;
  if (result == NULL) {
    error = 1;
  } else {
    int sgn = get_sign(value);
    int r_sgn = sgn == 0 ? 1 : 0;
    *result = value;
    set_sign(result, r_sgn);
  }
  return error;
}

// Auxiliary functions
void bigdecimal_add(big_decimal v_1, big_decimal v_2,
                        big_decimal *res) {
  init_big_by_zeroes(res);
  int in_mind = 0;

  for (int i = 0; i < 192; i++) {
    int v1_bit = get_big_bit(v_1, i);
    int v2_bit = get_big_bit(v_2, i);
    int sum = v1_bit + v2_bit + in_mind;
    int res_bit = sum % 2;
    in_mind = sum > 1 ? 1 : 0;
    set_big_bit(res, i, res_bit);
  }
}

void bigdecimal_sub(big_decimal v_1, big_decimal v_2,
                        big_decimal *res) {
  init_big_by_zeroes(res);
  int loaned = 0;
  for (int i = 0; i < 192; i++) {
    int v1_bit = get_big_bit(v_1, i);
    int v2_bit = get_big_bit(v_2, i);
    int added = v1_bit - v2_bit - loaned < 0 ? 2 : 0;
    int sub = v1_bit - v2_bit - loaned + added;
    loaned = added == 0 ? 0 : 1;
    int res_bit = sub % 2;
    set_big_bit(res, i, res_bit);
  }
}

void bigdecimal_mul(big_decimal v_1, big_decimal v_2,
                        big_decimal *res) {
  init_big_by_zeroes(res);
  big_decimal temp;
  temp = v_1;
  int last_index = last_big_bit_index(v_2);
  for (int i = 0; i <= last_index; i++) {
    int v2_bit = get_big_bit(v_2, i);
    if (v2_bit == 1) bigdecimal_add(*res, temp, res);
    shift_left(&temp);
  }
}

big_decimal bigdecimal_div(big_decimal v_1, big_decimal v_2,
                                   big_decimal *res) {
  init_big_by_zeroes(res);
  int count = 191;
  big_decimal remain, temp_res;
  init_big_by_zeroes(&temp_res);
  init_big_by_zeroes(&remain);

  int dividend_size = last_big_bit_index(v_1) + 1;
  int divisor_size = last_big_bit_index(v_2) + 1;
  int remain_bits = dividend_size - divisor_size;

  big_decimal dividend_part = get_dividend_part(v_1, divisor_size);
  if (remain_bits < 0) remain = v_1;
  while (remain_bits >= 0) {
    int bit = get_big_bit(v_1, remain_bits - 1);
    if (bigdecimal_is_less(dividend_part, v_2)) {
      remain = dividend_part;
      shift_left(&dividend_part);
      set_big_bit(&dividend_part, 0, bit);
      set_big_bit(&temp_res, count--, 0);
    } else {
      bigdecimal_sub(dividend_part, v_2, &dividend_part);
      remain = dividend_part;
      shift_left(&dividend_part);
      set_big_bit(&dividend_part, 0, bit);
      set_big_bit(&temp_res, count--, 1);
    }
    remain_bits--;
  }

  for (int i = 191, j = i - count - 1; j >= 0; j--) {
    int bit = get_big_bit(temp_res, i--);
    set_big_bit(res, j, bit);
  }
  return remain;
}

int get_big_bit(big_decimal value, int index) {
  int bits_index = index / 32;
  int int_index = 31 - index % 32;
  int bit = -1;
  if (index > -1 && index < 192) {
    value.bits[bits_index] = value.bits[bits_index] << int_index;
    value.bits[bits_index] = value.bits[bits_index] >> 31;
    bit = value.bits[bits_index] == 0 ? 0 : 1;
  }
  return bit;
}

void set_big_bit(big_decimal *value, int index, int bit) {
  int bits_index = index / 32;
  int int_index = 31 - index % 32;

  if (bit == 1) {
    int mask = 1 << (31 - int_index);
    (*value).bits[bits_index] |= mask;
  } else {
    int mask = ~(1 << (31 - int_index));
    (*value).bits[bits_index] &= mask;
  }
}

int get_bit(decimal value, int index) {
  int bits_index = index / 32;
  int int_index = 31 - index % 32;
  int bit = -1;
  if (index > -1 && index < 96) {
    value.bits[bits_index] = value.bits[bits_index] << int_index;
    value.bits[bits_index] = value.bits[bits_index] >> 31;
    bit = value.bits[bits_index] == 0 ? 0 : 1;
  }
  return bit;
}

void set_bit(decimal *value, int index, int bit) {
  int bits_index = index / 32;
  int int_index = 31 - index % 32;

  if (bit == 1) {
    int mask = 1 << (31 - int_index);
    (*value).bits[bits_index] |= mask;
  } else {
    int mask = ~(1 << (31 - int_index));
    (*value).bits[bits_index] &= mask;
  }
}

unsigned int get_sign(decimal value) { return value.bits[3] >> 31; }

void set_sign(decimal *value, unsigned int sign) {
  unsigned int one = 1;
  if (sign == 1) {
    unsigned int mask = (one << 31);
    value->bits[3] = value->bits[3] | mask;
  } else {
    unsigned int mask = ~(one << 31);
    value->bits[3] = value->bits[3] & mask;
  }
}

int get_scale(decimal value) {
  unsigned int scale = 0;
  if (value.bits[3] != MINUS && value.bits[3] != PLUS) {
    for (int i = 16; i <= 20; i++) {
      unsigned int bit = (value.bits[3] >> i) & 1;
      scale |= (bit << (i - 16));
    }
  }
  return (int)scale;
}

void set_scale(decimal *value, int scale) {
  for (int i = 20, j = 4; i >= 16; i--, j--) {
    int bit = (scale >> j) & 1;
    if (bit) {
      (*value).bits[3] |= (bit << i);
    } else {
      (*value).bits[3] &= ~(1 << i);
    }
  }
}

int get_floatexp(decimal src) {
  int e = 0;
  decimal one, two;
  init_by_zeroes(&one);
  init_by_zeroes(&two);
  one.bits[0] = 1;
  two.bits[0] = 2;
  if (is_less(src, one)) {
    while (is_less(src, one)) {
      mul(src, two, &src);
      e--;
    }
  } else {
    while (is_less(one, src)) {
      div(src, two, &src);
      if (is_less_or_equal(one, src)) e++;
    }
  }
  return e;
}

big_decimal get_dividend_part(big_decimal dividend, int bitness) {
  big_decimal result;
  init_big_by_zeroes(&result);
  int start = last_big_bit_index(dividend);
  int index = bitness - 1;

  for (int i = 0; i < bitness; i++) {
    int bit = get_big_bit(dividend, start - i);
    set_big_bit(&result, index, bit);
    index--;
  }
  return result;
}

big_decimal get_big_decimal_10() {
  big_decimal ten;
  init_big_by_zeroes(&ten);
  set_big_bit(&ten, 3, 1);
  set_big_bit(&ten, 1, 1);
  return ten;
}

int bigdecimal_is_less(big_decimal v1, big_decimal v2) {
  int arg = FALSE;
  int flag = 0;
  for (int i = 5; i >= 0 && !flag; i--) {
    if (v1.bits[i] > v2.bits[i]) {
      arg = FALSE;
      flag = 1;
    } else if (v1.bits[i] < v2.bits[i]) {
      arg = TRUE;
      flag = 1;
    }
  }
  return arg;
}

int big_decimal_zero(big_decimal v) {
  int arg = FALSE;
  if (!v.bits[0] && !v.bits[1] && !v.bits[2] && !v.bits[3] && !v.bits[4] &&
      !v.bits[5])
    arg = TRUE;
  return arg;
}

int decimal_zero(decimal v) {
  int arg = FALSE;
  if (!v.bits[0] && !v.bits[1] && !v.bits[2]) arg = TRUE;
  return arg;
}

void normalize_big(big_decimal *v_1, big_decimal *v_2, int *scl1,
                       int *scl2) {
  while (*scl1 != *scl2) {
    if (*scl1 < *scl2) {
      bigdecimal_mul(*v_1, get_big_decimal_10(), v_1);
      (*scl1)++;
    } else {
      bigdecimal_mul(*v_2, get_big_decimal_10(), v_2);
      (*scl2)++;
    }
  }
}

int reduce_scale(big_decimal *value, int *scale) {
  int code;
  int prev_zeroes = TRUE;
  int rounder = -1;
  big_decimal remain;

  while (last_big_bit_index(*value) > 95 && *scale > 0) {
    remain = bigdecimal_div(*value, get_big_decimal_10(), value);
    (*scale)--;
    if (last_big_bit_index(*value) < 96) {
      rounder = remain.bits[0] < 5 ? 0 : remain.bits[0] > 5 ? 1 : rounder;
      if (rounder == -1)
        rounder = !prev_zeroes ? 1 : get_big_bit(*value, 0) ? 1 : 0;
      big_decimal big_rounder;
      init_big_by_zeroes(&big_rounder);
      if (rounder == 1) set_big_bit(&big_rounder, 0, 1);
      bigdecimal_add(*value, big_rounder, value);
    } else {
      prev_zeroes = big_decimal_zero(remain) ? TRUE : FALSE;
    }
  }
  code = last_big_bit_index(*value) < 96 ? 0 : 1;
  return code;
}

void reduce_to_7(decimal *value) {
  int scl = get_scale(*value);
  int snums = 0;
  int not_0_found = 0;
  int scl_reduced = 0;
  int prev_zeroes = 1;
  int mul = 0;
  big_decimal tmp = decimal_to_big(*value);
  big_decimal norm_num, tmp2, remain;
  init_big_by_zeroes(&remain);
  while (big_decimal_zero(tmp) != 1) {
    tmp2 = tmp;
    remain = bigdecimal_div(tmp, get_big_decimal_10(), &tmp);
    if (big_decimal_zero(remain) == 1 && !not_0_found) {
      scl--;
      continue;
    }
    not_0_found = 1;
    if (!scl_reduced) {
      norm_num = tmp2;
      scl_reduced = 1;
    }
    snums++;
  }

  while (snums > 7) {
    remain = bigdecimal_div(norm_num, get_big_decimal_10(), &norm_num);
    if (big_decimal_zero(remain) != 1) prev_zeroes = 0;
    snums--;
    mul++;
  }

  bank_round(&norm_num, remain, prev_zeroes);
  while (mul > 0) {
    bigdecimal_mul(norm_num, get_big_decimal_10(), &norm_num);
    mul--;
  }
  *value = big_to_decimal(norm_num);
  set_scale(value, scl);
}

void reduce_floatexp(decimal *src, int exp) {
  decimal two;
  init_by_zeroes(&two);
  two.bits[0] = 2;
  if (exp > 0) {
    while (exp > 0) {
      div(*src, two, src);
      exp--;
    }
  } else {
    while (exp < 0) {
      mul(*src, two, src);
      exp++;
    }
  }
}

void bank_round(big_decimal *value, big_decimal remain,
                    int prev_zeroes) {
  int rounder = -1;
  rounder = remain.bits[0] < 5 ? 0 : remain.bits[0] > 5 ? 1 : rounder;
  if (rounder == -1)
    rounder = !prev_zeroes ? 1 : get_big_bit(*value, 0) ? 1 : 0;
  big_decimal big_rounder;
  init_big_by_zeroes(&big_rounder);
  if (rounder == 1) set_big_bit(&big_rounder, 0, 1);
  bigdecimal_add(*value, big_rounder, value);
}

int last_big_bit_index(big_decimal value) {
  int index = -1;
  for (int i = 191; i >= 0 && index == -1; i--) {
    if (get_big_bit(value, i) == 1) index = i;
  }
  return index;
}

int last_bit_index(decimal value) {
  int index = -1;
  for (int i = 95; i >= 0 && index == -1; i--) {
    if (get_bit(value, i) == 1) index = i;
  }
  return index;
}

void shift_left(big_decimal *value) {
  int shift_bit1 = get_big_bit(*value, 31);
  (*value).bits[0] = (*value).bits[0] << 1;
  for (int i = 1; i < 6; i++) {
    int shift_bit2 = get_big_bit(*value, (32 * (i + 1) - 1));
    (*value).bits[i] = (*value).bits[i] << 1;
    if (shift_bit1 == 1) set_big_bit(value, 32 * i, 1);
    shift_bit1 = shift_bit2;
  }
}

big_decimal decimal_to_big(decimal value) {
  big_decimal result;
  init_big_by_zeroes(&result);
  for (int i = 0; i < 3; i++) {
    result.bits[i] = value.bits[i];
  }
  return result;
}

decimal big_to_decimal(big_decimal value) {
  decimal result;
  init_by_zeroes(&result);
  for (int i = 0; i < 3; i++) {
    result.bits[i] = value.bits[i];
  }
  return result;
}

void init_by_zeroes(decimal *value) {
  (*value).bits[0] = 0;
  (*value).bits[1] = 0;
  (*value).bits[2] = 0;
  (*value).bits[3] = 0;
}

void init_big_by_zeroes(big_decimal *value) {
  (*value).bits[0] = 0;
  (*value).bits[1] = 0;
  (*value).bits[2] = 0;
  (*value).bits[3] = 0;
  (*value).bits[4] = 0;
  (*value).bits[5] = 0;
}

int pow(int base, int exp) {
  int result = 1;
  for (int i = 1; i <= exp; i++) {
    result *= base;
  }
  return result;
}

