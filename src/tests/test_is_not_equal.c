#include "test.h"

START_TEST(s21_is_not_equal_test_1) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000000000111;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b00000000000000000000000000000111;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_test_2) {
  float num1 = 3.00036;
  float num2 = 1.359;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_test_3) {
  float num1 = 5.25;
  float num2 = 5.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_test_4) {
  float num1 = 5.25;
  float num2 = -5.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_test_5) {
  float num1 = 0;
  float num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_test_6) {
  float num1 = 0;
  float num2 = 654467;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_test_7) {
  float num1 = -1255264;
  float num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_test_8) {
  float num1 = 357765444654.36;
  float num2 = 15776776544.359;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_test_9) {
  float num1 = -357765444654.36;
  float num2 = 15776776544.359;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_test_10) {
  float num1 = 357765444654.36;
  float num2 = -15776776544.359;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *suite = suite_create("test_is_not_equal");
  TCase *tc = tcase_create("test_is_not_equal");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_is_not_equal_test_1);
  tcase_add_test(tc, s21_is_not_equal_test_2);
  tcase_add_test(tc, s21_is_not_equal_test_3);
  tcase_add_test(tc, s21_is_not_equal_test_4);
  tcase_add_test(tc, s21_is_not_equal_test_5);
  tcase_add_test(tc, s21_is_not_equal_test_6);
  tcase_add_test(tc, s21_is_not_equal_test_7);
  tcase_add_test(tc, s21_is_not_equal_test_8);
  tcase_add_test(tc, s21_is_not_equal_test_9);
  tcase_add_test(tc, s21_is_not_equal_test_10);

  return suite;
}