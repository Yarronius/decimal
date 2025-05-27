#include "test.h"

START_TEST(s21_from_int_to_decimal_test_1) {
  int num = 31496322;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num, value.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_2) {
  int num = -31496322;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num * -1, value.bits[0]);
  ck_assert_int_eq(2147483648, value.bits[3]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_3) {
  int num = 312;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num, value.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_4) {
  int num = -312;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num * -1, value.bits[0]);
  ck_assert_int_eq(2147483648, value.bits[3]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_5) {
  int num = 0;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num, value.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_6) {
  int num = -1;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num * -1, value.bits[0]);
  ck_assert_int_eq(2147483648, value.bits[3]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_7) {
  int num = 2147483647;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num, value.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_8) {
  int num = -2147483647;
  s21_decimal value;
  s21_init_by_zeroes(&value);
  int code = s21_from_int_to_decimal(num, &value);

  ck_assert_int_eq(num * -1, value.bits[0]);
  ck_assert_int_eq(2147483648, value.bits[3]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_9) {
  int num = 125332152;
  int code = s21_from_int_to_decimal(num, NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_10) {
  int num = -125122552;
  int code = s21_from_int_to_decimal(num, NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_from_int_to_decimal() {
  Suite *suite = suite_create("test_from_int_to_decimal");
  TCase *tc = tcase_create("test_from_int_to_decimal");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_from_int_to_decimal_test_1);
  tcase_add_test(tc, s21_from_int_to_decimal_test_2);
  tcase_add_test(tc, s21_from_int_to_decimal_test_3);
  tcase_add_test(tc, s21_from_int_to_decimal_test_4);
  tcase_add_test(tc, s21_from_int_to_decimal_test_5);
  tcase_add_test(tc, s21_from_int_to_decimal_test_6);
  tcase_add_test(tc, s21_from_int_to_decimal_test_7);
  tcase_add_test(tc, s21_from_int_to_decimal_test_8);
  tcase_add_test(tc, s21_from_int_to_decimal_test_9);
  tcase_add_test(tc, s21_from_int_to_decimal_test_10);

  return suite;
}