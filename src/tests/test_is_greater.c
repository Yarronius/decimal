#include "test.h"

START_TEST(s21_is_greater_test_1) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_greater_test_2) {
  int num1 = 5;
  int num2 = 88;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_greater_test_3) {
  int num1 = 11;
  int num2 = 4;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_greater_test_4) {
  s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};
  s21_decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};
  ck_assert_int_eq(s21_is_greater(dec1, dec2), 1);
  ck_assert_int_eq(s21_is_greater(dec2, dec1), 0);
}
END_TEST

START_TEST(s21_is_greater_test_5) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000000000011;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b00000000000000000000000000000011;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(s21_is_greater_test_6) {
  int num1 = -9;
  int num2 = -19;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res1 = s21_is_greater(dec1, dec2);
  int res2 = s21_is_greater(dec2, dec1);
  ck_assert_int_eq(res1, TRUE);
  ck_assert_int_eq(res2, FALSE);
}
END_TEST

START_TEST(s21_is_greater_test_7) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000000000010;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  dec2.bits[0] = 0b00000000000000000000000000000000;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(s21_is_greater_test_8) {
  s21_decimal dec1 = {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal dec2 = {{0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000}};
  ck_assert_int_eq(s21_is_greater(dec1, dec2), 0);
}
END_TEST

START_TEST(s21_is_greater_test_9) {
  float num1 = 3.00036;
  float num2 = 1.359;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(s21_is_greater_test_10) {
  float num1 = 5.25;
  float num2 = 5.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(s21_is_greater_test_11) {
  float num1 = 5.25;
  float num2 = -5.25;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res1 = s21_is_greater(dec1, dec2);
  int res2 = s21_is_greater(dec2, dec1);
  ck_assert_int_eq(res1, TRUE);
  ck_assert_int_eq(res2, FALSE);
}
END_TEST

Suite *test_is_greater(void) {
  Suite *suite = suite_create("test_is_greater");
  TCase *tc = tcase_create("test_is_greater");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_is_greater_test_1);
  tcase_add_test(tc, s21_is_greater_test_2);
  tcase_add_test(tc, s21_is_greater_test_3);
  tcase_add_test(tc, s21_is_greater_test_4);
  tcase_add_test(tc, s21_is_greater_test_5);
  tcase_add_test(tc, s21_is_greater_test_6);
  tcase_add_test(tc, s21_is_greater_test_7);
  tcase_add_test(tc, s21_is_greater_test_8);
  tcase_add_test(tc, s21_is_greater_test_9);
  tcase_add_test(tc, s21_is_greater_test_10);
  tcase_add_test(tc, s21_is_greater_test_11);

  return suite;
}