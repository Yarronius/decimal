#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MINUS 0b10000000000000000000000000000000
#define PLUS 0b00000000000000000000000000000000

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
} s21_big_decimal;

// Main functions
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal v1, s21_decimal v2);
int s21_is_less_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_greater(s21_decimal v1, s21_decimal v2);
int s21_is_greater_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_equal(s21_decimal v1, s21_decimal v2);
int s21_is_not_equal(s21_decimal v1, s21_decimal v2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Auxiliary functions
void s21_bigdecimal_add(s21_big_decimal v_1, s21_big_decimal v_2,
                        s21_big_decimal *res);
void s21_bigdecimal_sub(s21_big_decimal v_1, s21_big_decimal v_2,
                        s21_big_decimal *res);
void s21_bigdecimal_mul(s21_big_decimal v_1, s21_big_decimal v_2,
                        s21_big_decimal *res);
s21_big_decimal s21_bigdecimal_div(s21_big_decimal v_1, s21_big_decimal v_2,
                                   s21_big_decimal *res);

int s21_get_big_bit(s21_big_decimal value, int index);
void s21_set_big_bit(s21_big_decimal *value, int index, int bit);
int s21_get_bit(s21_decimal value, int index);
void s21_set_bit(s21_decimal *value, int index, int bit);
unsigned int s21_get_sign(s21_decimal value);
void s21_set_sign(s21_decimal *value, unsigned int sign);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, int scale);
int s21_get_floatexp(s21_decimal src);
s21_big_decimal s21_get_dividend_part(s21_big_decimal dividend, int bitness);
s21_big_decimal s21_get_big_decimal_10();

int s21_bigdecimal_is_less(s21_big_decimal v1, s21_big_decimal v2);
int s21_big_decimal_zero(s21_big_decimal v);
int s21_decimal_zero(s21_decimal v);

void s21_normalize_big(s21_big_decimal *v_1, s21_big_decimal *v_2,
                       int *v1_scale, int *v2_scale);
int s21_reduce_scale(s21_big_decimal *value, int *scale);
void s21_reduce_to_7(s21_decimal *value);
void s21_reduce_floatexp(s21_decimal *src, int exp);
void s21_bank_round(s21_big_decimal *value, s21_big_decimal remain,
                    int prev_zeroes);

int s21_last_big_bit_index(s21_big_decimal value);
int s21_last_bit_index(s21_decimal value);
void s21_shift_left(s21_big_decimal *value);

s21_big_decimal s21_decimal_to_big(s21_decimal value);
s21_decimal s21_big_to_decimal(s21_big_decimal value);

void s21_init_by_zeroes(s21_decimal *value);
void s21_init_big_by_zeroes(s21_big_decimal *value);

int s21_pow(int base, int exp);

#endif