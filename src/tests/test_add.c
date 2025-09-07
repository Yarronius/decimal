#include "test.h"

START_TEST(add_test_0) {
  int a = 0;
  int b = 0;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_1) {
  int a = 89;
  int b = 12;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_2) {
  int a = 89;
  int b = -12;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_3) {
  int a = -89;
  int b = 12;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_4) {
  int a = -89;
  int b = -12;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_5) {
  int a = 0;
  int b = 12;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_6) {
  int a = 0;
  int b = -12;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_7) {
  int a = 89;
  int b = 0;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = from_decimal_to_int(result, &sum);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_8) {
  int a = -89;
  int b = 0;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = from_decimal_to_int(result, &sum);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}

START_TEST(add_test_9) {
  int a = 12;
  int b = 89;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_10) {
  int a = 12;
  int b = -89;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_11) {
  int a = -12;
  int b = 89;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_12) {
  int a = -12;
  int b = -89;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_13) {
  int a = 785421235;
  int b = 258745212;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_14) {
  int a = 785421235;
  int b = -258745212;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_15) {
  int a = -785421235;
  int b = 258745212;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_16) {
  int a = -785421235;
  int b = -258745212;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_17) {
  int a = 0;
  int b = 258745212;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_18) {
  int a = 0;
  int b = -258745212;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_19) {
  int a = 785421235;
  int b = 0;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = from_decimal_to_int(result, &sum);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_20) {
  int a = -785421235;
  int b = 0;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = from_decimal_to_int(result, &sum);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}

START_TEST(add_test_21) {
  int a = 258745212;
  int b = 785421235;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_22) {
  int a = 258745212;
  int b = -785421235;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_23) {
  int a = -258745212;
  int b = 785421235;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_24) {
  int a = -258745212;
  int b = -785421235;
  int sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_int(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_25) {
  float a = 89.76578f;
  float b = 12.23568f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_float_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_26) {
  float a = 89.76578f;
  float b = -12.23568f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_float_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_27) {
  float a = -89.76578f;
  float b = 12.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_28) {
  float a = -89.765786f;
  float b = -12.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_29) {
  float a = 0;
  float b = 12.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_30) {
  float a = 0;
  float b = -12.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_31) {
  float a = 89.765786f;
  float b = 0;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_32) {
  float a = -89.765786f;
  float b = 0;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}

START_TEST(add_test_33) {
  float a = 12.235681f;
  float b = 89.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_34) {
  float a = 12.235681f;
  float b = -89.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_35) {
  float a = -12.235681f;
  float b = 89.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_36) {
  float a = -12.235681f;
  float b = -89.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_37) {
  float a = 89565465.765786f;
  float b = 12455443.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_38) {
  float a = 89565465.765786f;
  float b = -12455443.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_39) {
  float a = -89565465.765786f;
  float b = 12455443.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_40) {
  float a = -89565465.765786f;
  float b = -12455443.235681f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_41) {
  float a = 12455443.235681f;
  float b = 89565465.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_42) {
  float a = 12455443.235681f;
  float b = -89565465.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = add(value1, value2, &result);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_43) {
  float a = -12455443.235681f;
  float b = 89565465.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = from_decimal_to_float(result, &sum);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_44) {
  float a = -12455443.235681f;
  float b = -89565465.765786f;
  float sum;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  add(value1, value2, &result);
  int code = from_decimal_to_float(result, &sum);
  from_decimal_to_float(result, &sum);
  ck_assert_int_eq(sum, a + b);
  ck_assert_int_eq(code, 0);
}

START_TEST(add_test_45) {
  decimal value1;  // value1 = 79228162514264337593543950335
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;  // value2 = -0.6
  value2.bits[3] = 0b10000000000000010000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal expected;  // expected = 79228162514264337593543950334
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b11111111111111111111111111111111;
  expected.bits[1] = 0b11111111111111111111111111111111;
  expected.bits[0] = 0b11111111111111111111111111111110;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_46) {
  decimal value1;  // value1 = -79228162514264337593543950335
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;  // value2 = 0.6
  value2.bits[3] = 0b00000000000000010000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal expected;  // expected = -79228162514264337593543950334
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b11111111111111111111111111111111;
  expected.bits[1] = 0b11111111111111111111111111111111;
  expected.bits[0] = 0b11111111111111111111111111111110;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_47) {
  decimal value1;  // value1 = 79228162514264337593543950334
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111110;

  decimal value2;  // value2 = 0.6
  value2.bits[3] = 0b00000000000000010000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal expected;  // expected = 79228162514264337593543950335
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b11111111111111111111111111111111;
  expected.bits[1] = 0b11111111111111111111111111111111;
  expected.bits[0] = 0b11111111111111111111111111111111;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_48) {
  decimal value1;  // value1 = 293628689466015337846
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000001111;
  value1.bits[1] = 0b11101010111010101010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 20098374384509231789
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000001;
  value2.bits[1] = 0b00010110111010111100010100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 313727063850524569635
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000010001;
  expected.bits[1] = 0b00000001110101100110111001011111;
  expected.bits[0] = 0b11110100110011110111000000100011;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_49) {
  decimal value1;  // value1 = 293628689466015337846
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000001111;
  value1.bits[1] = 0b11101010111010101010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = -20098374384509231789
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000001;
  value2.bits[1] = 0b00010110111010111100010100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 273530315081506106057
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000001110;
  expected.bits[1] = 0b11010011111111101110010001010111;
  expected.bits[0] = 0b01000101110110000010101011001001;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_50) {
  decimal value1;  // value1 = -293628689466015337846
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000001111;
  value1.bits[1] = 0b11101010111010101010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 20098374384509231789
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000001;
  value2.bits[1] = 0b00010110111010111100010100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = -273530315081506106057
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000001110;
  expected.bits[1] = 0b11010011111111101110010001010111;
  expected.bits[0] = 0b01000101110110000010101011001001;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_51) {
  decimal value1;  // value1 = -293628689466015337846
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000001111;
  value1.bits[1] = 0b11101010111010101010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = -20098374384509231789
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000001;
  value2.bits[1] = 0b00010110111010111100010100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = -313727063850524569635
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000010001;
  expected.bits[1] = 0b00000001110101100110111001011111;
  expected.bits[0] = 0b11110100110011110111000000100011;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_52) {  // positive overflow
  decimal value1;
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b01111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b10101011011111011111001101111111;

  decimal value2;
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b01111111111111111111111111111111;
  value2.bits[1] = 0b10101010101010101010101010111111;
  value2.bits[0] = 0b11111111111111111111111111111111;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_53) {  // negative overflow
  decimal value1;
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b01111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b10101011011111011111001101111111;

  decimal value2;
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b01111111111111111111111111111111;
  value2.bits[1] = 0b10101010101010101010101010111111;
  value2.bits[0] = 0b11111111111111111111111111111111;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_test_54) {
  decimal value1;
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b01111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b01111111111111111111111111111111;
  value2.bits[1] = 0b11111111111111111111111111111111;
  value2.bits[0] = 0b11111111111111111111111111111111;

  decimal expected;
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  decimal result;
  init_by_zeroes(&result);

  int code = add(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *test_add(void) {
  Suite *suite = suite_create("test_add");
  TCase *tc = tcase_create("test_add");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, add_test_0);
  tcase_add_test(tc, add_test_1);
  tcase_add_test(tc, add_test_2);
  tcase_add_test(tc, add_test_3);
  tcase_add_test(tc, add_test_4);
  tcase_add_test(tc, add_test_5);
  tcase_add_test(tc, add_test_6);
  tcase_add_test(tc, add_test_7);
  tcase_add_test(tc, add_test_8);
  tcase_add_test(tc, add_test_9);
  tcase_add_test(tc, add_test_10);
  tcase_add_test(tc, add_test_11);
  tcase_add_test(tc, add_test_12);
  tcase_add_test(tc, add_test_13);
  tcase_add_test(tc, add_test_14);
  tcase_add_test(tc, add_test_15);
  tcase_add_test(tc, add_test_16);
  tcase_add_test(tc, add_test_17);
  tcase_add_test(tc, add_test_18);
  tcase_add_test(tc, add_test_19);
  tcase_add_test(tc, add_test_20);
  tcase_add_test(tc, add_test_21);
  tcase_add_test(tc, add_test_22);
  tcase_add_test(tc, add_test_23);
  tcase_add_test(tc, add_test_24);
  tcase_add_test(tc, add_test_25);
  tcase_add_test(tc, add_test_26);
  tcase_add_test(tc, add_test_27);
  tcase_add_test(tc, add_test_28);
  tcase_add_test(tc, add_test_29);
  tcase_add_test(tc, add_test_30);
  tcase_add_test(tc, add_test_31);
  tcase_add_test(tc, add_test_32);
  tcase_add_test(tc, add_test_33);
  tcase_add_test(tc, add_test_34);
  tcase_add_test(tc, add_test_35);
  tcase_add_test(tc, add_test_36);
  tcase_add_test(tc, add_test_37);
  tcase_add_test(tc, add_test_38);
  tcase_add_test(tc, add_test_39);
  tcase_add_test(tc, add_test_40);
  tcase_add_test(tc, add_test_41);
  tcase_add_test(tc, add_test_42);
  tcase_add_test(tc, add_test_43);
  tcase_add_test(tc, add_test_44);
  tcase_add_test(tc, add_test_45);
  tcase_add_test(tc, add_test_46);
  tcase_add_test(tc, add_test_47);
  tcase_add_test(tc, add_test_48);
  tcase_add_test(tc, add_test_49);
  tcase_add_test(tc, add_test_50);
  tcase_add_test(tc, add_test_51);
  tcase_add_test(tc, add_test_52);
  tcase_add_test(tc, add_test_53);
  tcase_add_test(tc, add_test_54);

  return suite;

}
