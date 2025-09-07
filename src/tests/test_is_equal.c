#include "test.h"

START_TEST(is_equal_test_1) {
  int num1 = 3;
  int num2 = 3;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_equal_test_2) {
  int num1 = 0;
  int num2 = 0;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_equal_test_3) {
  int num1 = -5;
  int num2 = -5;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_equal_test_4) {
  decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000000000111;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b00000000000000000000000000000111;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(dec1, dec2);
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_equal_test_5) {
  decimal dec1 = {{12345, 0, 0, 0b00000000000000000000000000001000}};
  decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};
  ck_assert_int_eq(is_equal(dec1, dec2), 0);
}
END_TEST

START_TEST(is_equal_test_6) {
  decimal dec1 = {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000}};
  decimal dec2 = {{0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000}};
  ck_assert_int_eq(is_equal(dec1, dec2), 0);
}
END_TEST

START_TEST(is_equal_test_7) {
  float num1 = 3.00036;
  float num2 = 1.359;
  decimal dec1, dec2;
  init_by_zeroes(&dec1);
  init_by_zeroes(&dec2);
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(is_equal_test_8) {
  float num1 = 5.25;
  float num2 = 5.25;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_equal_test_9) {
  float num1 = 5.25;
  float num2 = -5.25;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(is_equal_test_10) {
  decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000000000111;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b00000000000000000000000000000111;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b10000000000000000000000000000000;
  int result = is_equal(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_equal_test_11) {
  decimal dec1, dec2;
  dec1.bits[0] = 0b00000000000000000000000000000111;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000000000000000000000000;

  dec2.bits[0] = 0b00000000000000000000000000000111;
  dec2.bits[1] = 0b00000000000000000000000000000000;
  dec2.bits[2] = 0b00000000000000000000000000000000;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_equal_test_12) {
  decimal dec1, dec2;
  dec1.bits[0] = 0b11111111111111110000000101010010;
  dec1.bits[1] = 0b00000001010111110101111111100101;
  dec1.bits[2] = 0b11110101100010100101101100010101;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b11111111111111110000000101010010;
  dec2.bits[1] = 0b00000001010111110101111111100101;
  dec2.bits[2] = 0b11110101100010100101101100010101;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(dec1, dec2);
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_equal_test_13) {
  decimal dec1, dec2;
  dec1.bits[0] = 0b11111111111111110000000101010011;
  dec1.bits[1] = 0b00000001010111110101111111100101;
  dec1.bits[2] = 0b11110101100010100101101100010101;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b11111111111111110000000101010010;
  dec2.bits[1] = 0b00000001010111110101111111100101;
  dec2.bits[2] = 0b11110101100010100101101100010101;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_equal_test_14) {
  decimal dec1, dec2;
  dec1.bits[0] = 0b11111111111111110000000101010010;
  dec1.bits[1] = 0b00000001010111110101111111100101;
  dec1.bits[2] = 0b11110101100010100101101100010101;
  dec1.bits[3] = 0b00000000000000100000000000000000;

  dec2.bits[0] = 0b11111111111111110000000101010010;
  dec2.bits[1] = 0b00000001010111110101111111100101;
  dec2.bits[2] = 0b11110101100010100101101100010101;
  dec2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_equal(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_equal_test_15) {
  decimal dec1, dec2;
  dec1.bits[0] = 0b11111111111111110000000101010010;
  dec1.bits[1] = 0b00000001010111110101111111100101;
  dec1.bits[2] = 0b11110101100010100101101100010101;
  dec1.bits[3] = 0b00000000000000000000000000000000;

  dec2.bits[0] = 0b11111111111111110000000101010010;
  dec2.bits[1] = 0b00000001010111110101111111100101;
  dec2.bits[2] = 0b11110101100010100101101100010101;
  dec2.bits[3] = 0b00000000000001100000000000000000;
  int result = is_equal(dec1, dec2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

Suite *test_is_equal(void) {
  Suite *suite = suite_create("test_is_equal");
  TCase *tc = tcase_create("test_is_equal");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, is_equal_test_1);
  tcase_add_test(tc, is_equal_test_2);
  tcase_add_test(tc, is_equal_test_3);
  tcase_add_test(tc, is_equal_test_4);
  tcase_add_test(tc, is_equal_test_5);
  tcase_add_test(tc, is_equal_test_6);
  tcase_add_test(tc, is_equal_test_7);
  tcase_add_test(tc, is_equal_test_8);
  tcase_add_test(tc, is_equal_test_9);
  tcase_add_test(tc, is_equal_test_10);
  tcase_add_test(tc, is_equal_test_11);
  tcase_add_test(tc, is_equal_test_12);
  tcase_add_test(tc, is_equal_test_13);
  tcase_add_test(tc, is_equal_test_14);
  tcase_add_test(tc, is_equal_test_15);

  return suite;

}
