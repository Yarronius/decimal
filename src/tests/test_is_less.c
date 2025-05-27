#include "test.h"

START_TEST(s21_is_less_test_1) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_less_test_2) {
  int num1 = 1;
  int num2 = 14;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_less_test_3) {
  int num1 = 51;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_less_test_4) {
  s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};
  s21_decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};
  ck_assert_int_eq(s21_is_less(dec1, dec2), 0);
  ck_assert_int_eq(s21_is_less(dec2, dec1), 1);
}
END_TEST

START_TEST(s21_is_less_test_5) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000010000011;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b00000000000000000000000000000011;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(s21_is_less_test_6) {
  int num1 = -11;
  int num2 = -23;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res1 = s21_is_less(dec1, dec2);
  int res2 = s21_is_less(dec2, dec1);
  ck_assert_int_eq(res1, FALSE);
  ck_assert_int_eq(res2, TRUE);
}
END_TEST

START_TEST(s21_is_less_test_7) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000000000010;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  dec2.bits[0] = 0b00000000000000000000000000000001;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int res1 = s21_is_less(dec1, dec2);
  int res2 = s21_is_less(dec2, dec1);
  ck_assert_int_eq(res1, FALSE);
  ck_assert_int_eq(res2, TRUE);
}
END_TEST

START_TEST(s21_is_less_test_8) {
  float num1 = 3.00036;
  float num2 = 1.359;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_less_test_9) {
  float num1 = 5.25;
  float num2 = 5.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_less_test_10) {
  float num1 = 5.25;
  float num2 = -5.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res1 = s21_is_less(dec1, dec2);
  int res2 = s21_is_less(dec2, dec1);
  ck_assert_int_eq(res1, FALSE);
  ck_assert_int_eq(res2, TRUE);
}
END_TEST

START_TEST(s21_is_less_test_11) {
  float num1 = 5.25;
  float num2 = -1.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res1 = s21_is_less(dec1, dec2);
  int res2 = s21_is_less(dec2, dec1);
  ck_assert_int_eq(res1, FALSE);
  ck_assert_int_eq(res2, TRUE);
}
END_TEST

START_TEST(s21_is_less_test_12) {
  float num1 = -5.25;
  float num2 = -1.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res1 = s21_is_less(dec1, dec2);
  int res2 = s21_is_less(dec2, dec1);
  ck_assert_int_eq(res1, TRUE);
  ck_assert_int_eq(res2, FALSE);
}
END_TEST

Suite *test_is_less(void) {
  Suite *suite = suite_create("test_is_less");
  TCase *tc = tcase_create("test_is_less");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_is_less_test_1);
  tcase_add_test(tc, s21_is_less_test_2);
  tcase_add_test(tc, s21_is_less_test_3);
  tcase_add_test(tc, s21_is_less_test_4);
  tcase_add_test(tc, s21_is_less_test_5);
  tcase_add_test(tc, s21_is_less_test_6);
  tcase_add_test(tc, s21_is_less_test_7);
  tcase_add_test(tc, s21_is_less_test_8);
  tcase_add_test(tc, s21_is_less_test_9);
  tcase_add_test(tc, s21_is_less_test_10);
  tcase_add_test(tc, s21_is_less_test_11);
  tcase_add_test(tc, s21_is_less_test_12);

  return suite;
}