#include "s21_decimal.h"

// Main functions
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  int sgn1 = (int)s21_get_sign(value_1);
  int sgn2 = (int)s21_get_sign(value_2);

  int scl1 = s21_get_scale(value_1);
  int scl2 = s21_get_scale(value_2);

  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  int signs_not_eq = (sgn1 + sgn2) % 2;

  if (signs_not_eq) {
    s21_decimal tmp1 = sgn1 == 0 ? value_1 : value_2;
    s21_decimal tmp2 = sgn2 == 0 ? value_1 : value_2;

    code = s21_sub(tmp1, tmp2, result);
    sgn1 = s21_is_less(tmp1, tmp2) ? 1 : 0;

  } else {
    s21_big_decimal tmp_r;
    s21_big_decimal tmp1 = s21_decimal_to_big(value_1);
    s21_big_decimal tmp2 = s21_decimal_to_big(value_2);
    s21_normalize_big(&tmp1, &tmp2, &scl1, &scl2);
    s21_bigdecimal_add(tmp1, tmp2, &tmp_r);

    if (tmp_r.bits[5] || tmp_r.bits[4] || tmp_r.bits[3]) {
      code = s21_reduce_scale(&tmp_r, &scl1);
    }
    *result = s21_big_to_decimal(tmp_r);
    s21_set_scale(result, scl1);
  }

  s21_set_sign(result, sgn1);
  if (sgn1 + sgn2 == 2 && code == 1) code++;

  return code;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  unsigned int sgn1 = s21_get_sign(value_1);
  unsigned int sgn2 = s21_get_sign(value_2);
  int scl1 = s21_get_scale(value_1);
  int scl2 = s21_get_scale(value_2);

  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);

  s21_big_decimal tmp1 = s21_decimal_to_big(value_1);
  s21_big_decimal tmp2 = s21_decimal_to_big(value_2);
  s21_big_decimal tmp_r;

  s21_normalize_big(&tmp1, &tmp2, &scl1, &scl2);

  if (sgn1 + sgn2 == 1) {
    s21_bigdecimal_add(tmp1, tmp2, &tmp_r);
  } else if (s21_is_less(value_1, value_2)) {
    s21_bigdecimal_sub(tmp2, tmp1, &tmp_r);
    sgn1 = sgn1 == 0 ? 1 : 0;
  } else {
    s21_bigdecimal_sub(tmp1, tmp2, &tmp_r);
  }

  if (tmp_r.bits[5] || tmp_r.bits[4] || tmp_r.bits[3]) {
    code = s21_reduce_scale(&tmp_r, &scl1);
  }
  *result = s21_big_to_decimal(tmp_r);
  s21_set_scale(result, scl1);
  s21_set_sign(result, sgn1);
  return code;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code;
  int r_sgn = ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31)) % 2;

  int scl1 = s21_get_scale(value_1);
  int scl2 = s21_get_scale(value_2);
  int r_scl = scl1 + scl2;

  s21_big_decimal tmp1 = s21_decimal_to_big(value_1);
  s21_big_decimal tmp2 = s21_decimal_to_big(value_2);
  s21_big_decimal tmp_r;

  s21_bigdecimal_mul(tmp1, tmp2, &tmp_r);
  code = s21_reduce_scale(&tmp_r, &r_scl);
  *result = s21_big_to_decimal(tmp_r);
  s21_set_sign(result, r_sgn);
  s21_set_scale(result, r_scl);
  if (r_sgn == 1 && code == 1) code++;

  return code;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_init_by_zeroes(result);
  int code = 0;
  if (s21_decimal_zero(value_2) == 1) {
    code = 3;
  } else if (s21_decimal_zero(value_1) != 1) {
    s21_big_decimal tmp1 = s21_decimal_to_big(value_1);
    s21_big_decimal tmp2 = s21_decimal_to_big(value_2);
    int sgn = ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31)) % 2;

    int scl1 = s21_get_scale(value_1);
    int scl2 = s21_get_scale(value_2);
    int r_scl = scl1 - scl2;

    s21_big_decimal tmp_r, remain;
    while (s21_bigdecimal_is_less(tmp1, tmp2) && r_scl < 28) {
      s21_bigdecimal_mul(tmp1, s21_get_big_decimal_10(), &tmp1);
      r_scl++;
    }

    if (s21_bigdecimal_is_less(tmp1, tmp2) != 1) {
      remain = s21_bigdecimal_div(tmp1, tmp2, &tmp_r);

      while (s21_big_decimal_zero(remain) != 1 && r_scl < 28) {
        s21_bigdecimal_mul(tmp1, s21_get_big_decimal_10(), &tmp1);
        remain = s21_bigdecimal_div(tmp1, tmp2, &tmp_r);
        r_scl++;
      }
      while (r_scl < 0) {
        s21_bigdecimal_mul(tmp_r, s21_get_big_decimal_10(), &tmp_r);
        r_scl++;
      }

      code = s21_reduce_scale(&tmp_r, &r_scl);
      *result = s21_big_to_decimal(tmp_r);
      s21_set_sign(result, sgn);
      s21_set_scale(result, r_scl);
      if (sgn == 1 && code == 1) code++;
    } else if (s21_decimal_zero(value_1) != 1) {
      code = 1;
    }
  }
  return code;
}

int s21_is_less(s21_decimal v1, s21_decimal v2) {
  int arg = FALSE;
  int flag = 0;
  int s1 = (int)s21_get_sign(v1);
  int s2 = (int)s21_get_sign(v2);

  if (s1 && !s2) {
    arg = TRUE;
  } else if (!s1 && s2) {
    arg = FALSE;
  } else {
    s21_big_decimal t1 = s21_decimal_to_big(v1);
    s21_big_decimal t2 = s21_decimal_to_big(v2);
    int scl1 = s21_get_scale(v1);
    int scl2 = s21_get_scale(v2);
    s21_normalize_big(&t1, &t2, &scl1, &scl2);

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

int s21_is_less_or_equal(s21_decimal v1, s21_decimal v2) {
  return !s21_is_greater(v1, v2);
}

int s21_is_greater(s21_decimal v1, s21_decimal v2) {
  int arg = FALSE;
  int flag = 0;
  int s1 = (int)s21_get_sign(v1);
  int s2 = (int)s21_get_sign(v2);
  if (s1 && !s2) {
    arg = FALSE;
  } else if (!s1 && s2) {
    arg = TRUE;
  } else {
    s21_big_decimal t1 = s21_decimal_to_big(v1);
    s21_big_decimal t2 = s21_decimal_to_big(v2);
    int scl1 = s21_get_scale(v1);
    int scl2 = s21_get_scale(v2);
    s21_normalize_big(&t1, &t2, &scl1, &scl2);

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

int s21_is_greater_or_equal(s21_decimal v1, s21_decimal v2) {
  return !s21_is_less(v1, v2);
}

int s21_is_equal(s21_decimal v1, s21_decimal v2) {
  int arg = TRUE;
  int s1 = (int)s21_get_sign(v1);
  int s2 = (int)s21_get_sign(v2);
  if (s21_decimal_zero(v1) && s21_decimal_zero(v2)) {
    arg = TRUE;
  } else if (s1 != s2) {
    arg = FALSE;
  } else {
    s21_big_decimal t1 = s21_decimal_to_big(v1);
    s21_big_decimal t2 = s21_decimal_to_big(v2);
    int scl1 = s21_get_scale(v1);
    int scl2 = s21_get_scale(v2);
    s21_normalize_big(&t1, &t2, &scl1, &scl2);

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

int s21_is_not_equal(s21_decimal v1, s21_decimal v2) {
  return !s21_is_equal(v1, v2);
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (dst == NULL) {
    error = 1;
  } else {
    s21_init_by_zeroes(dst);
    int sgn = src < 0 ? 1 : 0;
    src = src < 0 ? src * -1 : src;
    dst->bits[0] = src;
    s21_set_sign(dst, sgn);
  }
  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_decimal mant, exp, two;
  s21_init_by_zeroes(&mant);
  s21_init_by_zeroes(&exp);
  s21_init_by_zeroes(&two);
  s21_init_by_zeroes(dst);
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
      code = s21_mul(exp, two, &exp);
    } else {
      code = s21_div(exp, two, &exp);
    }
  }
  if (code == 0) {
    s21_set_bit(&mant, 23, 1);

    for (int i = 0; i < 23; i++) {
      s21_div(mant, two, &mant);
    }
    code = s21_mul(mant, exp, dst);
    s21_reduce_to_7(dst);
    s21_set_sign(dst, sign);
  }
  if (code != 0) s21_init_by_zeroes(dst);
  if (src == 0) code = 0;
  return code == 0 ? 0 : 1;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  int degree = s21_get_scale(src);
  s21_big_decimal temp = s21_decimal_to_big(src);
  if (s21_get_scale(src) > 0) {
    while (degree != 0) {
      s21_bigdecimal_div(temp, s21_get_big_decimal_10(), &temp);
      degree -= 1;
    }
  }

  if (temp.bits[1] || temp.bits[2] || temp.bits[3] || temp.bits[4] ||
      temp.bits[5] || s21_get_big_bit(temp, 31)) {
    error = 1;
  } else {
    *dst = temp.bits[0];
    *dst = s21_get_sign(src) == 0 ? *dst : *dst * -1;
  }

  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int code = 0;
  if (s21_decimal_zero(src) != 1) {
    s21_decimal two;
    s21_init_by_zeroes(&two);
    two.bits[0] = 2;
    int sgn = s21_get_sign(src);
    s21_set_sign(&src, 0);

    int e = s21_get_floatexp(src);
    int shifte = e + 127;
    s21_reduce_floatexp(&src, e);

    for (int i = 0; i < 23; i++) {
      s21_mul(src, two, &src);
    }
    int scale = s21_get_scale(src);

    s21_big_decimal bigtmp = s21_decimal_to_big(src);
    int prev_zeroes = TRUE;
    s21_big_decimal remain;
    s21_init_big_by_zeroes(&remain);
    for (int i = 0; i < scale; i++) {
      remain = s21_bigdecimal_div(bigtmp, s21_get_big_decimal_10(), &bigtmp);
      prev_zeroes = s21_big_decimal_zero(remain) ? TRUE : FALSE;
    }
    s21_bank_round(&bigtmp, remain, prev_zeroes);
    src = s21_big_to_decimal(bigtmp);

    unsigned int result = *dst;
    if (s21_last_bit_index(src) > 24) {
      code = 1;
    } else {
      s21_set_bit(&src, 23, 0);
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

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int sign = s21_get_sign(value);

  if (result == NULL) {
    error = 1;
  } else {
    if (value.bits[3] == PLUS || value.bits[3] == MINUS) {
      *result = value;
    } else {
      if (sign == 0) {
        s21_truncate(value, result);
      } else if (sign == 1) {
        int degree = s21_get_scale(value);
        int power_of_ten = s21_pow(10, degree);
        s21_decimal remainder;  // дробная часть
        s21_decimal trunc;      // убрали дробную часть
        s21_decimal unit_for_rounding;
        int unit = -1;
        s21_init_by_zeroes(&remainder);
        s21_init_by_zeroes(&trunc);
        s21_truncate(value, &trunc);
        s21_init_by_zeroes(&unit_for_rounding);
        s21_from_int_to_decimal(unit, &unit_for_rounding);
        s21_sub(value, trunc, &remainder);
        int rest_remainder;
        s21_from_decimal_to_int(remainder, &rest_remainder);
        if (rest_remainder / power_of_ten < 5) {
          s21_add(trunc, unit_for_rounding, result);
        } else {
          *result = trunc;
        }
      }
    }
  }
  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int sign = s21_get_sign(value);

  if (result == NULL) {
    error = 1;
  } else {
    s21_decimal remainder;  // дробная часть
    s21_decimal trunc;      // убрали дробную часть
    int unit = sign == 0 ? 1 : -1;
    s21_decimal unit_for_rounding;
    s21_init_by_zeroes(&remainder);
    s21_init_by_zeroes(&trunc);
    s21_truncate(value, &trunc);
    s21_init_by_zeroes(&unit_for_rounding);
    s21_from_int_to_decimal(unit, &unit_for_rounding);
    s21_sub(value, trunc, &remainder);
    float rest_remainder;
    s21_from_decimal_to_float(remainder, &rest_remainder);
    if (rest_remainder != 0 && (int)(rest_remainder * 10 * unit) >= 5) {
      s21_add(trunc, unit_for_rounding, result);
    } else {
      *result = trunc;
    }
  }
  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result == NULL) {
    error = 1;
  } else {
    s21_decimal ten_degree;
    s21_big_decimal power_of_ten;
    s21_init_by_zeroes(result);
    s21_init_by_zeroes(&ten_degree);
    s21_init_big_by_zeroes(&power_of_ten);

    power_of_ten.bits[0] = 1;
    int degree = s21_get_scale(value);
    int sgn = s21_get_sign(value);
    if (s21_get_scale(value) > 0) {
      while (degree != 0) {
        s21_bigdecimal_mul(power_of_ten, s21_get_big_decimal_10(),
                           &power_of_ten);
        degree -= 1;
      }
      s21_big_decimal temp = s21_decimal_to_big(value);
      s21_bigdecimal_div(temp, power_of_ten, &temp);
      *result = s21_big_to_decimal(temp);
      s21_set_sign(result, sgn);
    } else {
      *result = value;
    }
  }
  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result == NULL) {
    error = 1;
  } else {
    int sgn = s21_get_sign(value);
    int r_sgn = sgn == 0 ? 1 : 0;
    *result = value;
    s21_set_sign(result, r_sgn);
  }
  return error;
}

// Auxiliary functions
void s21_bigdecimal_add(s21_big_decimal v_1, s21_big_decimal v_2,
                        s21_big_decimal *res) {
  s21_init_big_by_zeroes(res);
  int in_mind = 0;

  for (int i = 0; i < 192; i++) {
    int v1_bit = s21_get_big_bit(v_1, i);
    int v2_bit = s21_get_big_bit(v_2, i);
    int sum = v1_bit + v2_bit + in_mind;
    int res_bit = sum % 2;
    in_mind = sum > 1 ? 1 : 0;
    s21_set_big_bit(res, i, res_bit);
  }
}

void s21_bigdecimal_sub(s21_big_decimal v_1, s21_big_decimal v_2,
                        s21_big_decimal *res) {
  s21_init_big_by_zeroes(res);
  int loaned = 0;
  for (int i = 0; i < 192; i++) {
    int v1_bit = s21_get_big_bit(v_1, i);
    int v2_bit = s21_get_big_bit(v_2, i);
    int added = v1_bit - v2_bit - loaned < 0 ? 2 : 0;
    int sub = v1_bit - v2_bit - loaned + added;
    loaned = added == 0 ? 0 : 1;
    int res_bit = sub % 2;
    s21_set_big_bit(res, i, res_bit);
  }
}

void s21_bigdecimal_mul(s21_big_decimal v_1, s21_big_decimal v_2,
                        s21_big_decimal *res) {
  s21_init_big_by_zeroes(res);
  s21_big_decimal temp;
  temp = v_1;
  int last_index = s21_last_big_bit_index(v_2);
  for (int i = 0; i <= last_index; i++) {
    int v2_bit = s21_get_big_bit(v_2, i);
    if (v2_bit == 1) s21_bigdecimal_add(*res, temp, res);
    s21_shift_left(&temp);
  }
}

s21_big_decimal s21_bigdecimal_div(s21_big_decimal v_1, s21_big_decimal v_2,
                                   s21_big_decimal *res) {
  s21_init_big_by_zeroes(res);
  int count = 191;
  s21_big_decimal remain, temp_res;
  s21_init_big_by_zeroes(&temp_res);
  s21_init_big_by_zeroes(&remain);

  int dividend_size = s21_last_big_bit_index(v_1) + 1;
  int divisor_size = s21_last_big_bit_index(v_2) + 1;
  int remain_bits = dividend_size - divisor_size;

  s21_big_decimal dividend_part = s21_get_dividend_part(v_1, divisor_size);
  if (remain_bits < 0) remain = v_1;
  while (remain_bits >= 0) {
    int bit = s21_get_big_bit(v_1, remain_bits - 1);
    if (s21_bigdecimal_is_less(dividend_part, v_2)) {
      remain = dividend_part;
      s21_shift_left(&dividend_part);
      s21_set_big_bit(&dividend_part, 0, bit);
      s21_set_big_bit(&temp_res, count--, 0);
    } else {
      s21_bigdecimal_sub(dividend_part, v_2, &dividend_part);
      remain = dividend_part;
      s21_shift_left(&dividend_part);
      s21_set_big_bit(&dividend_part, 0, bit);
      s21_set_big_bit(&temp_res, count--, 1);
    }
    remain_bits--;
  }

  for (int i = 191, j = i - count - 1; j >= 0; j--) {
    int bit = s21_get_big_bit(temp_res, i--);
    s21_set_big_bit(res, j, bit);
  }
  return remain;
}

int s21_get_big_bit(s21_big_decimal value, int index) {
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

void s21_set_big_bit(s21_big_decimal *value, int index, int bit) {
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

int s21_get_bit(s21_decimal value, int index) {
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

void s21_set_bit(s21_decimal *value, int index, int bit) {
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

unsigned int s21_get_sign(s21_decimal value) { return value.bits[3] >> 31; }

void s21_set_sign(s21_decimal *value, unsigned int sign) {
  unsigned int one = 1;
  if (sign == 1) {
    unsigned int mask = (one << 31);
    value->bits[3] = value->bits[3] | mask;
  } else {
    unsigned int mask = ~(one << 31);
    value->bits[3] = value->bits[3] & mask;
  }
}

int s21_get_scale(s21_decimal value) {
  unsigned int scale = 0;
  if (value.bits[3] != MINUS && value.bits[3] != PLUS) {
    for (int i = 16; i <= 20; i++) {
      unsigned int bit = (value.bits[3] >> i) & 1;
      scale |= (bit << (i - 16));
    }
  }
  return (int)scale;
}

void s21_set_scale(s21_decimal *value, int scale) {
  for (int i = 20, j = 4; i >= 16; i--, j--) {
    int bit = (scale >> j) & 1;
    if (bit) {
      (*value).bits[3] |= (bit << i);
    } else {
      (*value).bits[3] &= ~(1 << i);
    }
  }
}

int s21_get_floatexp(s21_decimal src) {
  int e = 0;
  s21_decimal one, two;
  s21_init_by_zeroes(&one);
  s21_init_by_zeroes(&two);
  one.bits[0] = 1;
  two.bits[0] = 2;
  if (s21_is_less(src, one)) {
    while (s21_is_less(src, one)) {
      s21_mul(src, two, &src);
      e--;
    }
  } else {
    while (s21_is_less(one, src)) {
      s21_div(src, two, &src);
      if (s21_is_less_or_equal(one, src)) e++;
    }
  }
  return e;
}

s21_big_decimal s21_get_dividend_part(s21_big_decimal dividend, int bitness) {
  s21_big_decimal result;
  s21_init_big_by_zeroes(&result);
  int start = s21_last_big_bit_index(dividend);
  int index = bitness - 1;

  for (int i = 0; i < bitness; i++) {
    int bit = s21_get_big_bit(dividend, start - i);
    s21_set_big_bit(&result, index, bit);
    index--;
  }
  return result;
}

s21_big_decimal s21_get_big_decimal_10() {
  s21_big_decimal ten;
  s21_init_big_by_zeroes(&ten);
  s21_set_big_bit(&ten, 3, 1);
  s21_set_big_bit(&ten, 1, 1);
  return ten;
}

int s21_bigdecimal_is_less(s21_big_decimal v1, s21_big_decimal v2) {
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

int s21_big_decimal_zero(s21_big_decimal v) {
  int arg = FALSE;
  if (!v.bits[0] && !v.bits[1] && !v.bits[2] && !v.bits[3] && !v.bits[4] &&
      !v.bits[5])
    arg = TRUE;
  return arg;
}

int s21_decimal_zero(s21_decimal v) {
  int arg = FALSE;
  if (!v.bits[0] && !v.bits[1] && !v.bits[2]) arg = TRUE;
  return arg;
}

void s21_normalize_big(s21_big_decimal *v_1, s21_big_decimal *v_2, int *scl1,
                       int *scl2) {
  while (*scl1 != *scl2) {
    if (*scl1 < *scl2) {
      s21_bigdecimal_mul(*v_1, s21_get_big_decimal_10(), v_1);
      (*scl1)++;
    } else {
      s21_bigdecimal_mul(*v_2, s21_get_big_decimal_10(), v_2);
      (*scl2)++;
    }
  }
}

int s21_reduce_scale(s21_big_decimal *value, int *scale) {
  int code;
  int prev_zeroes = TRUE;
  int rounder = -1;
  s21_big_decimal remain;

  while (s21_last_big_bit_index(*value) > 95 && *scale > 0) {
    remain = s21_bigdecimal_div(*value, s21_get_big_decimal_10(), value);
    (*scale)--;
    if (s21_last_big_bit_index(*value) < 96) {
      rounder = remain.bits[0] < 5 ? 0 : remain.bits[0] > 5 ? 1 : rounder;
      if (rounder == -1)
        rounder = !prev_zeroes ? 1 : s21_get_big_bit(*value, 0) ? 1 : 0;
      s21_big_decimal big_rounder;
      s21_init_big_by_zeroes(&big_rounder);
      if (rounder == 1) s21_set_big_bit(&big_rounder, 0, 1);
      s21_bigdecimal_add(*value, big_rounder, value);
    } else {
      prev_zeroes = s21_big_decimal_zero(remain) ? TRUE : FALSE;
    }
  }
  code = s21_last_big_bit_index(*value) < 96 ? 0 : 1;
  return code;
}

void s21_reduce_to_7(s21_decimal *value) {
  int scl = s21_get_scale(*value);
  int snums = 0;
  int not_0_found = 0;
  int scl_reduced = 0;
  int prev_zeroes = 1;
  int mul = 0;
  s21_big_decimal tmp = s21_decimal_to_big(*value);
  s21_big_decimal norm_num, tmp2, remain;
  s21_init_big_by_zeroes(&remain);
  while (s21_big_decimal_zero(tmp) != 1) {
    tmp2 = tmp;
    remain = s21_bigdecimal_div(tmp, s21_get_big_decimal_10(), &tmp);
    if (s21_big_decimal_zero(remain) == 1 && !not_0_found) {
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
    remain = s21_bigdecimal_div(norm_num, s21_get_big_decimal_10(), &norm_num);
    if (s21_big_decimal_zero(remain) != 1) prev_zeroes = 0;
    snums--;
    mul++;
  }

  s21_bank_round(&norm_num, remain, prev_zeroes);
  while (mul > 0) {
    s21_bigdecimal_mul(norm_num, s21_get_big_decimal_10(), &norm_num);
    mul--;
  }
  *value = s21_big_to_decimal(norm_num);
  s21_set_scale(value, scl);
}

void s21_reduce_floatexp(s21_decimal *src, int exp) {
  s21_decimal two;
  s21_init_by_zeroes(&two);
  two.bits[0] = 2;
  if (exp > 0) {
    while (exp > 0) {
      s21_div(*src, two, src);
      exp--;
    }
  } else {
    while (exp < 0) {
      s21_mul(*src, two, src);
      exp++;
    }
  }
}

void s21_bank_round(s21_big_decimal *value, s21_big_decimal remain,
                    int prev_zeroes) {
  int rounder = -1;
  rounder = remain.bits[0] < 5 ? 0 : remain.bits[0] > 5 ? 1 : rounder;
  if (rounder == -1)
    rounder = !prev_zeroes ? 1 : s21_get_big_bit(*value, 0) ? 1 : 0;
  s21_big_decimal big_rounder;
  s21_init_big_by_zeroes(&big_rounder);
  if (rounder == 1) s21_set_big_bit(&big_rounder, 0, 1);
  s21_bigdecimal_add(*value, big_rounder, value);
}

int s21_last_big_bit_index(s21_big_decimal value) {
  int index = -1;
  for (int i = 191; i >= 0 && index == -1; i--) {
    if (s21_get_big_bit(value, i) == 1) index = i;
  }
  return index;
}

int s21_last_bit_index(s21_decimal value) {
  int index = -1;
  for (int i = 95; i >= 0 && index == -1; i--) {
    if (s21_get_bit(value, i) == 1) index = i;
  }
  return index;
}

void s21_shift_left(s21_big_decimal *value) {
  int shift_bit1 = s21_get_big_bit(*value, 31);
  (*value).bits[0] = (*value).bits[0] << 1;
  for (int i = 1; i < 6; i++) {
    int shift_bit2 = s21_get_big_bit(*value, (32 * (i + 1) - 1));
    (*value).bits[i] = (*value).bits[i] << 1;
    if (shift_bit1 == 1) s21_set_big_bit(value, 32 * i, 1);
    shift_bit1 = shift_bit2;
  }
}

s21_big_decimal s21_decimal_to_big(s21_decimal value) {
  s21_big_decimal result;
  s21_init_big_by_zeroes(&result);
  for (int i = 0; i < 3; i++) {
    result.bits[i] = value.bits[i];
  }
  return result;
}

s21_decimal s21_big_to_decimal(s21_big_decimal value) {
  s21_decimal result;
  s21_init_by_zeroes(&result);
  for (int i = 0; i < 3; i++) {
    result.bits[i] = value.bits[i];
  }
  return result;
}

void s21_init_by_zeroes(s21_decimal *value) {
  (*value).bits[0] = 0;
  (*value).bits[1] = 0;
  (*value).bits[2] = 0;
  (*value).bits[3] = 0;
}

void s21_init_big_by_zeroes(s21_big_decimal *value) {
  (*value).bits[0] = 0;
  (*value).bits[1] = 0;
  (*value).bits[2] = 0;
  (*value).bits[3] = 0;
  (*value).bits[4] = 0;
  (*value).bits[5] = 0;
}

int s21_pow(int base, int exp) {
  int result = 1;
  for (int i = 1; i <= exp; i++) {
    result *= base;
  }
  return result;
}
