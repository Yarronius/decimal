#include "test.h"

START_TEST(s21_truncate_test_1) {
  float num = 3.14;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_2) {
  float num = 3.94;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_3) {
  float num = -3.14;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_4) {
  float num = -3.94;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_5) {
  float num = 7389.145;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 7389);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_6) {
  float num = -7389.145;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -7389);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_7) {
  float num = 0.14;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_8) {
  float num = -0.94;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_9) {
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_init_by_zeroes(&value);
  s21_init_by_zeroes(&result);
  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_10) {
  float num = 125;
  int res;
  s21_decimal value;
  s21_decimal result;
  int code = s21_from_float_to_decimal(num, &value);
  s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 125);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_11) {
  s21_decimal value;
  s21_decimal expected;
  s21_decimal result;

  value.bits[3] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[0] = 0b11111111111111111111111111111111;

  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b11111111111111111111111111111111;
  expected.bits[1] = 0b11111111111111111111111111111111;
  expected.bits[0] = 0b11111111111111111111111111111111;

  int code = s21_truncate(value, &result);

  ck_assert_int_eq(expected.bits[3], result.bits[3]);
  ck_assert_int_eq(expected.bits[2], result.bits[2]);
  ck_assert_int_eq(expected.bits[1], result.bits[1]);
  ck_assert_int_eq(expected.bits[0], result.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_12) {
  s21_decimal value;     // 79228162514264337593543,950335
  s21_decimal expected;  // 79228162514264337593543
  s21_decimal result;

  value.bits[3] = 0b00000000000001100000000000000000;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[0] = 0b11111111111111111111111111111111;

  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000001000011000110;
  expected.bits[1] = 0b11110111101000001011010111101101;
  expected.bits[0] = 0b10001101001101101011010011000111;

  int code = s21_truncate(value, &result);

  ck_assert_int_eq(expected.bits[3], result.bits[3]);
  ck_assert_int_eq(expected.bits[2], result.bits[2]);
  ck_assert_int_eq(expected.bits[1], result.bits[1]);
  ck_assert_int_eq(expected.bits[0], result.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_13) {
  s21_decimal value;     //-79228162514264337593543,950335
  s21_decimal expected;  //-79228162514264337593543
  s21_decimal result;

  value.bits[3] = 0b10000000000001100000000000000000;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[0] = 0b11111111111111111111111111111111;

  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000001000011000110;
  expected.bits[1] = 0b11110111101000001011010111101101;
  expected.bits[0] = 0b10001101001101101011010011000111;

  int code = s21_truncate(value, &result);

  ck_assert_int_eq(expected.bits[3], result.bits[3]);
  ck_assert_int_eq(expected.bits[2], result.bits[2]);
  ck_assert_int_eq(expected.bits[1], result.bits[1]);
  ck_assert_int_eq(expected.bits[0], result.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_14) {
  s21_decimal value;     //-268.435433
  s21_decimal expected;  //-268
  s21_decimal result;

  value.bits[3] = 0b10000000000001100000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[0] = 0b00001111111111111111111111101001;

  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000100001100;

  int code = s21_truncate(value, &result);

  ck_assert_int_eq(expected.bits[3], result.bits[3]);
  ck_assert_int_eq(expected.bits[2], result.bits[2]);
  ck_assert_int_eq(expected.bits[1], result.bits[1]);
  ck_assert_int_eq(expected.bits[0], result.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_15) {
  float num = 3;
  int res;
  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);

  int code = s21_truncate(value, &result);
  s21_from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_test_16) {
  float num = 3;
  s21_decimal value;
  s21_from_float_to_decimal(num, &value);

  int code = s21_truncate(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_truncate(void) {
  Suite *suite = suite_create("test_truncate");
  TCase *tc = tcase_create("test_truncate");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_truncate_test_1);
  tcase_add_test(tc, s21_truncate_test_2);
  tcase_add_test(tc, s21_truncate_test_3);
  tcase_add_test(tc, s21_truncate_test_4);
  tcase_add_test(tc, s21_truncate_test_5);
  tcase_add_test(tc, s21_truncate_test_6);
  tcase_add_test(tc, s21_truncate_test_7);
  tcase_add_test(tc, s21_truncate_test_8);
  tcase_add_test(tc, s21_truncate_test_9);
  tcase_add_test(tc, s21_truncate_test_10);
  tcase_add_test(tc, s21_truncate_test_11);
  tcase_add_test(tc, s21_truncate_test_12);
  tcase_add_test(tc, s21_truncate_test_13);
  tcase_add_test(tc, s21_truncate_test_14);
  tcase_add_test(tc, s21_truncate_test_15);
  tcase_add_test(tc, s21_truncate_test_16);

  return suite;
}