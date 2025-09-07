#include "test.h"

START_TEST(from_decimal_to_int_test_1) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1452542;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(result, 1452542);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_test_2) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1452542;
  value.bits[3] = 2147483648;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(result, -1452542);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_test_3) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 0;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_test_4) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_test_5) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1;
  value.bits[3] = 2147483648;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(result, -1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(from_decimal_to_int_test_6) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1452542;
  value.bits[1] = 23515;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_test_7) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1452542;
  value.bits[1] = 23515;
  value.bits[3] = 2147483648;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_test_8) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1452542;
  value.bits[1] = 23515;
  value.bits[2] = 1218522;
  value.bits[3] = 2147483648;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_test_9) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1452542;
  value.bits[1] = 23515;
  value.bits[2] = 1218522;
  value.bits[3] = 0;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_test_10) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 1452542;
  value.bits[1] = 0;
  value.bits[2] = 1218522;
  value.bits[3] = 2147483648;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(from_decimal_to_int_test_11) {
  decimal value;
  init_by_zeroes(&value);
  value.bits[0] = 0;
  value.bits[1] = 0;
  value.bits[2] = 1218522;
  value.bits[3] = 2147483648;
  int result;
  int code = from_decimal_to_int(value, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_from_decimal_to_int() {
  Suite *suite = suite_create("test_from_decimal_to_int");
  TCase *tc = tcase_create("test_from_decimal_to_int");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, from_decimal_to_int_test_1);
  tcase_add_test(tc, from_decimal_to_int_test_2);
  tcase_add_test(tc, from_decimal_to_int_test_3);
  tcase_add_test(tc, from_decimal_to_int_test_4);
  tcase_add_test(tc, from_decimal_to_int_test_5);
  tcase_add_test(tc, from_decimal_to_int_test_6);
  tcase_add_test(tc, from_decimal_to_int_test_7);
  tcase_add_test(tc, from_decimal_to_int_test_8);
  tcase_add_test(tc, from_decimal_to_int_test_9);
  tcase_add_test(tc, from_decimal_to_int_test_10);
  tcase_add_test(tc, from_decimal_to_int_test_11);

  return suite;

}
