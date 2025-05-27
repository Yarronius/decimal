#include "test.h"

START_TEST(s21_negate_test_1) {
  float num = 3.14777;
  float res;

  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_negate(value, &result);
  s21_from_decimal_to_float(result, &res);

  ck_assert_float_eq(res, -3.14777);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_test_2) {
  float num = -3.14777;
  float res;

  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_negate(value, &result);
  s21_from_decimal_to_float(result, &res);

  ck_assert_float_eq(res, 3.14777);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_test_3) {
  float num = 36532.147;
  float res;

  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_negate(value, &result);
  s21_from_decimal_to_float(result, &res);

  ck_assert_float_eq(res, -36532.147);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_test_4) {
  float num = -36532.147;
  float res;

  s21_decimal value;
  s21_decimal result;
  s21_from_float_to_decimal(num, &value);
  int code = s21_negate(value, &result);
  s21_from_decimal_to_float(result, &res);

  ck_assert_float_eq(res, 36532.147);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_test_5) {
  s21_decimal value;
  s21_decimal result;
  s21_decimal expected;
  value.bits[3] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[0] = 0b11111111111111111111111111111111;

  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b11111111111111111111111111111111;
  expected.bits[1] = 0b11111111111111111111111111111111;
  expected.bits[0] = 0b11111111111111111111111111111111;
  int code = s21_negate(value, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_test_6) {
  s21_decimal value;
  s21_decimal result;
  s21_decimal expected;
  value.bits[3] = 0b10000000000000000000000000000000;
  value.bits[2] = 0b11111111110110001011101110110011;
  value.bits[1] = 0b11111101010101011100001010111111;
  value.bits[0] = 0b11100010100010110101010101111011;

  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b11111111110110001011101110110011;
  expected.bits[1] = 0b11111101010101011100001010111111;
  expected.bits[0] = 0b11100010100010110101010101111011;
  int code = s21_negate(value, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_test_7) {
  s21_decimal value;
  s21_decimal result;
  s21_decimal expected;
  value.bits[3] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[0] = 0b00000000000000000000000000000000;

  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;
  int code = s21_negate(value, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_test_8) {
  float num = -36532.147;

  s21_decimal value;
  s21_from_float_to_decimal(num, &value);
  int code = s21_negate(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_negate(void) {
  Suite *suite = suite_create("test_negate");
  TCase *tc = tcase_create("test_negate");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_negate_test_1);
  tcase_add_test(tc, s21_negate_test_2);
  tcase_add_test(tc, s21_negate_test_3);
  tcase_add_test(tc, s21_negate_test_4);
  tcase_add_test(tc, s21_negate_test_5);
  tcase_add_test(tc, s21_negate_test_6);
  tcase_add_test(tc, s21_negate_test_7);
  tcase_add_test(tc, s21_negate_test_8);
  return suite;
}