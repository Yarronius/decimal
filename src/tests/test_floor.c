#include "test.h"

START_TEST(s21_floor_test_1) {
  float num = 3.14;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_floor_test_2) {
  float num = -3.14;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -4);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_floor_test_3) {
  float num = 1234.945;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 1234);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_floor_test_4) {
  float num = -1234.94;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -1235);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_floor_test_5) {
  float num = 1234;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 1234);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_floor_test_6) {
  float num = -1234;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -1234);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_floor_test_7) {
  float num = 0;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_floor_test_8) {
  float num = 45896.21;
  s21_decimal value;

  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_floor_test_9) {
  float num = -45896.21;
  s21_decimal value;

  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_floor_test_10) {
  float num = 0;
  s21_decimal value;

  s21_from_float_to_decimal(num, &value);
  int code = s21_floor(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_floor() {
  Suite *suite = suite_create("test_floor");
  TCase *tc = tcase_create("test_floor");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_floor_test_1);
  tcase_add_test(tc, s21_floor_test_2);
  tcase_add_test(tc, s21_floor_test_3);
  tcase_add_test(tc, s21_floor_test_4);
  tcase_add_test(tc, s21_floor_test_5);
  tcase_add_test(tc, s21_floor_test_6);
  tcase_add_test(tc, s21_floor_test_7);
  tcase_add_test(tc, s21_floor_test_8);
  tcase_add_test(tc, s21_floor_test_9);
  tcase_add_test(tc, s21_floor_test_10);

  return suite;
}