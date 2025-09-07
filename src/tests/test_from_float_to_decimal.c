#include "test.h"

START_TEST(test_from_float_to_decimal_1) {
  float a = -3.141590f;

  decimal result;
  decimal expected;
  init_by_zeroes(&result);
  expected.bits[3] = 0b10000000000100100000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00101011100110010010101101110101;
  expected.bits[0] = 0b11001011111010110110000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_2) {
  float a = 3.141590f;

  decimal result;
  decimal expected;
  init_by_zeroes(&result);
  expected.bits[3] = 0b00000000000100100000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00101011100110010010101101110101;
  expected.bits[0] = 0b11001011111010110110000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_3) {
  float a = 0.141590f;

  decimal result;
  decimal expected;
  init_by_zeroes(&result);
  expected.bits[3] = 0b00000000000101110000000000000000;
  expected.bits[2] = 0b00000000000000000000001011111111;
  expected.bits[1] = 0b10001111100110001111101001100111;
  expected.bits[0] = 0b00100011110111000000000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_4) {
  float a = -0.141590f;

  decimal result;
  decimal expected;
  init_by_zeroes(&result);
  expected.bits[3] = 0b10000000000101110000000000000000;
  expected.bits[2] = 0b00000000000000000000001011111111;
  expected.bits[1] = 0b10001111100110001111101001100111;
  expected.bits[0] = 0b00100011110111000000000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_5) {
  float a = 10.14159f;

  decimal result;
  decimal expected;
  init_by_zeroes(&result);
  expected.bits[3] = 0b00000000000100100000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b10001100101111100010101001011111;
  expected.bits[0] = 0b01011111101001110110000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_6) {
  float a = -10.14159f;

  decimal result;
  decimal expected;
  init_by_zeroes(&result);
  expected.bits[3] = 0b10000000000100100000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b10001100101111100010101001011111;
  expected.bits[0] = 0b01011111101001110110000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_7) {
  float a = 0.0000000000000000000000000000000000014159f;

  decimal result;
  decimal expected;
  init_by_zeroes(&result);
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_8) {
  float a = 51815616513262126155161315151514.f;

  decimal result;
  init_by_zeroes(&result);

  int code = from_float_to_decimal(a, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_9) {
  float a = 0.f;

  decimal result;
  init_by_zeroes(&result);
  decimal expected;
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_10) {
  float a = 123356789.456f;

  decimal result;
  init_by_zeroes(&result);
  decimal expected;  // 123356800
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000111010110100100011010000000;

  int code = from_float_to_decimal(a, &result);

  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_11) {
  float a = 3.0;
  float b;

  decimal result;
  init_by_zeroes(&result);

  int code = from_float_to_decimal(a, &result);
  from_decimal_to_float(result, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *suite = suite_create("test_float_to_decimal");
  TCase *tc = tcase_create("test_float_to_decimal");

  suite_add_tcase(suite, tc);

  tcase_add_test(tc, test_from_float_to_decimal_1);
  tcase_add_test(tc, test_from_float_to_decimal_2);
  tcase_add_test(tc, test_from_float_to_decimal_3);
  tcase_add_test(tc, test_from_float_to_decimal_4);
  tcase_add_test(tc, test_from_float_to_decimal_5);
  tcase_add_test(tc, test_from_float_to_decimal_6);
  tcase_add_test(tc, test_from_float_to_decimal_7);
  tcase_add_test(tc, test_from_float_to_decimal_8);
  tcase_add_test(tc, test_from_float_to_decimal_9);
  tcase_add_test(tc, test_from_float_to_decimal_10);
  tcase_add_test(tc, test_from_float_to_decimal_11);

  return suite;
}

