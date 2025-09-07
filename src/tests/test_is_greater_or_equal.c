#include "test.h"

START_TEST(is_greater_or_equal_test_1) {
  int num1 = 0;
  int num2 = 0;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_test_2) {
  int num1 = 17;
  int num2 = 3;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_test_3) {
  int num1 = 3;
  int num2 = 41;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res1 = is_greater_or_equal(dec1, dec2);
  int res2 = is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res1, FALSE);
  ck_assert_int_eq(res2, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_test_4) {
  decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};
  decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};
  ck_assert_int_eq(is_greater_or_equal(dec1, dec2), 1);
  ck_assert_int_eq(is_greater_or_equal(dec2, dec1), 0);
}
END_TEST

START_TEST(is_greater_or_equal_test_5) {
  decimal dec1 = {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000}};
  decimal dec2 = {{0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000}};
  ck_assert_int_eq(is_greater_or_equal(dec1, dec2), 0);
  ck_assert_int_eq(is_greater_or_equal(dec2, dec1), 1);
}
END_TEST

START_TEST(is_greater_or_equal_test_6) {
  float num1 = 3.00036;
  float num2 = 1.359;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_test_7) {
  float num1 = 5.25;
  float num2 = 5.25;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_test_8) {
  float num1 = 5.25;
  float num2 = -5.25;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res1 = is_greater_or_equal(dec1, dec2);
  int res2 = is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res1, TRUE);
  ck_assert_int_eq(res2, FALSE);
}
END_TEST

START_TEST(is_greater_or_equal_test_9) {
  int num1 = -17;
  int num2 = 3;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(is_greater_or_equal_test_10) {
  int num1 = -3;
  int num2 = 41;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res1 = is_greater_or_equal(dec1, dec2);
  int res2 = is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res1, FALSE);
  ck_assert_int_eq(res2, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_test_11) {
  int num1 = 17;
  int num2 = -3;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_test_12) {
  int num1 = 3;
  int num2 = -41;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res1 = is_greater_or_equal(dec1, dec2);
  int res2 = is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res1, TRUE);
  ck_assert_int_eq(res2, FALSE);
}
END_TEST

START_TEST(is_greater_or_equal_test_13) {
  int num1 = -17;
  int num2 = -3;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(is_greater_or_equal_test_14) {
  int num1 = -3;
  int num2 = -41;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res1 = is_greater_or_equal(dec1, dec2);
  int res2 = is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res1, TRUE);
  ck_assert_int_eq(res2, FALSE);
}
END_TEST

Suite *test_is_greater_or_equal(void) {
  Suite *suite = suite_create("test_is_greater_or_equal");
  TCase *tc = tcase_create("test_is_greater_or_equal");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, is_greater_or_equal_test_1);
  tcase_add_test(tc, is_greater_or_equal_test_2);
  tcase_add_test(tc, is_greater_or_equal_test_3);
  tcase_add_test(tc, is_greater_or_equal_test_4);
  tcase_add_test(tc, is_greater_or_equal_test_5);
  tcase_add_test(tc, is_greater_or_equal_test_6);
  tcase_add_test(tc, is_greater_or_equal_test_7);
  tcase_add_test(tc, is_greater_or_equal_test_8);
  tcase_add_test(tc, is_greater_or_equal_test_9);
  tcase_add_test(tc, is_greater_or_equal_test_10);
  tcase_add_test(tc, is_greater_or_equal_test_11);
  tcase_add_test(tc, is_greater_or_equal_test_12);
  tcase_add_test(tc, is_greater_or_equal_test_13);
  tcase_add_test(tc, is_greater_or_equal_test_14);

  return suite;

}
