#define LEN 18

#include "test.h"

#include <check.h>

int main(void) {
  Suite* tests[LEN];
  int count = 0;

  Suite* add = test_add();
  Suite* sub = test_sub();
  Suite* mul = test_mul();
  Suite* div = test_div();

  Suite* is_less = test_is_less();
  Suite* is_less_or_equal = test_is_less_or_equal();
  Suite* is_greater = test_is_greater();
  Suite* is_greater_or_equal = test_is_greater_or_equal();
  Suite* is_equal = test_is_equal();
  Suite* is_not_equal = test_is_not_equal();

  Suite* from_int_to_decimal = test_from_int_to_decimal();
  Suite* from_float_to_decimal = test_from_float_to_decimal();
  Suite* from_decimal_to_int = test_from_decimal_to_int();
  Suite* from_decimal_to_float = test_from_decimal_to_float();
  Suite* floor = test_floor();
  Suite* round = test_round();
  Suite* truncate = test_truncate();
  Suite* negate = test_negate();

  tests[count++] = add;
  tests[count++] = sub;
  tests[count++] = mul;
  tests[count++] = div;

  tests[count++] = is_less;
  tests[count++] = is_less_or_equal;
  tests[count++] = is_greater;
  tests[count++] = is_greater_or_equal;
  tests[count++] = is_equal;
  tests[count++] = is_not_equal;

  tests[count++] = from_int_to_decimal;
  tests[count++] = from_float_to_decimal;
  tests[count++] = from_decimal_to_int;
  tests[count++] = from_decimal_to_float;

  tests[count++] = floor;
  tests[count++] = round;
  tests[count++] = truncate;
  tests[count++] = negate;

  for (int i = 0; i < LEN; i++) {
    SRunner* sr = srunner_create(tests[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_ENV);
    srunner_free(sr);
  }

  return 0;
}
