#include "test.h"

START_TEST(round_test_1) {
  float num = 3.14;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_2) {
  float num = 3.54;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 4);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_3) {
  float num = -3.14;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -3);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_4) {
  float num = -3.54;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -4);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_5) {
  float num = 345.1412;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 345);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_6) {
  float num = -345.1412;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -345);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_7) {
  float num = -345;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, -345);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_8) {
  float num = 345;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 345);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_9) {
  float num = 0;
  int res;
  decimal value;
  decimal result;
  from_float_to_decimal(num, &value);
  int code = round(value, &result);
  from_decimal_to_int(result, &res);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(round_test_10) {
  float num = 9523.2545;
  decimal value;
  from_float_to_decimal(num, &value);
  int code = round(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(round_test_11) {
  float num = -9523.2545;
  decimal value;
  from_float_to_decimal(num, &value);
  int code = round(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(round_test_12) {
  float num = 0;
  decimal value;
  from_float_to_decimal(num, &value);
  int code = round(value, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_round(void) {
  Suite *suite = suite_create("test_round");
  TCase *tc = tcase_create("test_round");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, round_test_1);
  tcase_add_test(tc, round_test_2);
  tcase_add_test(tc, round_test_3);
  tcase_add_test(tc, round_test_4);
  tcase_add_test(tc, round_test_5);
  tcase_add_test(tc, round_test_6);
  tcase_add_test(tc, round_test_7);
  tcase_add_test(tc, round_test_8);
  tcase_add_test(tc, round_test_9);
  tcase_add_test(tc, round_test_10);
  tcase_add_test(tc, round_test_11);
  tcase_add_test(tc, round_test_12);

  return suite;

}
