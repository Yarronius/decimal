#ifndef S21_DECIMAL_TESTS
#define S21_DECIMAL_TESTS

#include <check.h>

#include "../s21_decimal.h"

Suite* test_add();
Suite* test_sub();
Suite* test_mul();
Suite* test_div();

Suite* test_is_less();
Suite* test_is_less_or_equal();
Suite* test_is_greater();
Suite* test_is_greater_or_equal();
Suite* test_is_greater_or_equal();
Suite* test_is_equal();
Suite* test_is_not_equal();
Suite* test_from_int_to_decimal();
Suite* test_from_float_to_decimal();
Suite* test_from_decimal_to_int();
Suite* test_from_decimal_to_float();

Suite* test_floor();
Suite* test_round();
Suite* test_truncate();
Suite* test_negate();

#endif
