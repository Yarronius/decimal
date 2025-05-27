#include "test.h"

START_TEST(s21_test_from_decimal_to_float_1) {
  float a;

  s21_decimal dec;
  s21_init_by_zeroes(&dec);
  dec.bits[3] = 0b10000000000001100000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[0] = 0b00000000001011111110111111010110;

  int code = s21_from_decimal_to_float(dec, &a);
  ck_assert_float_eq(a, -3.14159);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_2) {
  float a;

  s21_decimal dec;
  s21_init_by_zeroes(&dec);
  dec.bits[3] = 0b00000000000001100000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[0] = 0b00000000001011111110111111010110;

  int code = s21_from_decimal_to_float(dec, &a);
  ck_assert_float_eq(a, 3.14159);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_3) {
  float a;

  s21_decimal dec;
  s21_init_by_zeroes(&dec);
  dec.bits[3] = 0b00000000000001100000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[0] = 0b00000000000000100010100100010110;

  int code = s21_from_decimal_to_float(dec, &a);

  ck_assert_float_eq(a, 0.141590);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_4) {
  float a;

  s21_decimal dec;
  s21_init_by_zeroes(&dec);
  dec.bits[3] = 0b10000000000001100000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[0] = 0b00000000000000100010100100010110;

  int code = s21_from_decimal_to_float(dec, &a);

  ck_assert_float_eq(a, -0.141590);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_5) {
  float a;

  s21_decimal dec;
  s21_init_by_zeroes(&dec);
  dec.bits[3] = 0b00000000000001100000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[0] = 0b00000000100110101011111110010110;

  int code = s21_from_decimal_to_float(dec, &a);

  ck_assert_float_eq(a, 10.14159);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_6) {
  float a;

  s21_decimal dec;
  s21_init_by_zeroes(&dec);
  dec.bits[3] = 0b10000000000001100000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[0] = 0b00000000100110101011111110010110;

  int code = s21_from_decimal_to_float(dec, &a);

  ck_assert_float_eq(a, -10.14159);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_7) {
  float a = 65676.4567;
  float b;
  s21_decimal dec;
  s21_from_float_to_decimal(a, &dec);
  int code = s21_from_decimal_to_float(dec, &b);

  ck_assert_float_eq(b, 65676.4567);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_8) {
  float a = -65676.4567;
  float b;
  s21_decimal dec;
  s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);

  int code = s21_from_decimal_to_float(dec, &a);

  ck_assert_float_eq(b, -65676.4567);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_9) {
  float a = -6.45654467;
  float b;
  s21_decimal dec;
  s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);

  int code = s21_from_decimal_to_float(dec, &a);

  ck_assert_float_eq(b, -6.45654467);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_10) {
  float a = -0.45657569;
  float b;
  s21_decimal dec;
  s21_from_float_to_decimal(a, &dec);
  int code = s21_from_decimal_to_float(dec, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_11) {
  float a = 0.123;
  float b;
  s21_decimal dec;
  s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);

  int code = s21_from_decimal_to_float(dec, &a);

  ck_assert_float_eq(b, 0.123);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_float_12) {
  float a;

  s21_decimal dec;
  s21_init_by_zeroes(&dec);
  dec.bits[3] = 0b00000000000000000000000000000000;
  dec.bits[2] = 0b00000000000000000000000000000000;
  dec.bits[1] = 0b00000000000000000000000000000000;
  dec.bits[0] = 0b00000000000000000000000000000000;

  int code = s21_from_decimal_to_float(dec, &a);
  ck_assert_float_eq(a, 0);
  ck_assert_int_eq(code, 0);
}

Suite *test_from_decimal_to_float(void) {
  Suite *suite = suite_create("test_decimal_to_float");
  TCase *tc = tcase_create("test_decimal_to_float");

  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_test_from_decimal_to_float_1);
  tcase_add_test(tc, s21_test_from_decimal_to_float_2);
  tcase_add_test(tc, s21_test_from_decimal_to_float_3);
  tcase_add_test(tc, s21_test_from_decimal_to_float_4);
  tcase_add_test(tc, s21_test_from_decimal_to_float_5);
  tcase_add_test(tc, s21_test_from_decimal_to_float_6);
  tcase_add_test(tc, s21_test_from_decimal_to_float_7);
  tcase_add_test(tc, s21_test_from_decimal_to_float_8);
  tcase_add_test(tc, s21_test_from_decimal_to_float_9);
  tcase_add_test(tc, s21_test_from_decimal_to_float_10);
  tcase_add_test(tc, s21_test_from_decimal_to_float_11);
  tcase_add_test(tc, s21_test_from_decimal_to_float_12);
  return suite;
}
