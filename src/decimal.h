#ifndef DECIMAL_H
#define DECIMAL_H
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MINUS 0b10000000000000000000000000000000
#define PLUS 0b00000000000000000000000000000000

typedef struct {
  unsigned int bits[4];
} decimal;

typedef struct {
  unsigned int bits[6];
} big_decimal;

// Main functions
int add(decimal value_1, decimal value_2, decimal *result);
int sub(decimal value_1, decimal value_2, decimal *result);
int mul(decimal value_1, decimal value_2, decimal *result);
int div(decimal value_1, decimal value_2, decimal *result);

int is_less(decimal v1, decimal v2);
int is_less_or_equal(decimal v1, decimal v2);
int is_greater(decimal v1, decimal v2);
int is_greater_or_equal(decimal v1, decimal v2);
int is_equal(decimal v1, decimal v2);
int is_not_equal(decimal v1, decimal v2);

int from_int_to_decimal(int src, decimal *dst);
int from_float_to_decimal(float src, decimal *dst);
int from_decimal_to_int(decimal src, int *dst);
int from_decimal_to_float(decimal src, float *dst);

int floor(decimal value, decimal *result);
int round(decimal value, decimal *result);
int truncate(decimal value, decimal *result);
int negate(decimal value, decimal *result);

// Auxiliary functions
void bigdecimal_add(big_decimal v_1, big_decimal v_2,
                        big_decimal *res);
void bigdecimal_sub(big_decimal v_1, big_decimal v_2,
                        big_decimal *res);
void bigdecimal_mul(big_decimal v_1, big_decimal v_2,
                        big_decimal *res);
big_decimal bigdecimal_div(big_decimal v_1, big_decimal v_2,
                                   big_decimal *res);

int get_big_bit(big_decimal value, int index);
void set_big_bit(big_decimal *value, int index, int bit);
int get_bit(decimal value, int index);
void set_bit(decimal *value, int index, int bit);
unsigned int get_sign(decimal value);
void set_sign(decimal *value, unsigned int sign);
int get_scale(decimal value);
void set_scale(decimal *value, int scale);
int get_floatexp(decimal src);
big_decimal get_dividend_part(big_decimal dividend, int bitness);
big_decimal get_big_decimal_10();

int bigdecimal_is_less(big_decimal v1, big_decimal v2);
int big_decimal_zero(big_decimal v);
int decimal_zero(decimal v);

void normalize_big(big_decimal *v_1, big_decimal *v_2,
                       int *v1_scale, int *v2_scale);
int reduce_scale(big_decimal *value, int *scale);
void reduce_to_7(decimal *value);
void reduce_floatexp(decimal *src, int exp);
void bank_round(big_decimal *value, big_decimal remain,
                    int prev_zeroes);

int last_big_bit_index(big_decimal value);
int last_bit_index(decimal value);
void shift_left(big_decimal *value);

big_decimal decimal_to_big(decimal value);
decimal big_to_decimal(big_decimal value);

void init_by_zeroes(decimal *value);
void init_big_by_zeroes(big_decimal *value);

int pow(int base, int exp);


#endif
