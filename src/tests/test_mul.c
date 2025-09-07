#include "test.h"

START_TEST(mul_test_0) {
  int a = 0;
  int b = 0;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_1) {
  int a = 89;
  int b = 12;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_2) {
  int a = 89;
  int b = -12;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_3) {
  int a = -89;
  int b = 12;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_4) {
  int a = -89;
  int b = -12;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_5) {
  int a = 0;
  int b = 12;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_6) {
  int a = 0;
  int b = -12;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_7) {
  int a = 89;
  int b = 0;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = from_decimal_to_int(result, &mul);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_8) {
  int a = -89;
  int b = 0;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = from_decimal_to_int(result, &mul);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}

START_TEST(mul_test_9) {
  int a = 12;
  int b = 89;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_10) {
  int a = 12;
  int b = -89;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_11) {
  int a = -12;
  int b = 89;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_12) {
  int a = -12;
  int b = -89;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_13) {
  int a = 78542;
  int b = 25874;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_14) {
  int a = 78542;
  int b = -25874;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_15) {
  int a = -78542;
  int b = 25874;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_16) {
  int a = -78542;
  int b = -25874;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_17) {
  int a = 0;
  int b = 25874;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_18) {
  int a = 0;
  int b = -25874;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_19) {
  int a = 78542;
  int b = 0;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = from_decimal_to_int(result, &mul);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_20) {
  int a = -78542;
  int b = 0;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = from_decimal_to_int(result, &mul);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}

START_TEST(mul_test_21) {
  int a = 25874;
  int b = 78542;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_22) {
  int a = 25874;
  int b = -78542;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_23) {
  int a = -25874;
  int b = 78542;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_24) {
  int a = -25874;
  int b = -78542;
  int mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_int_to_decimal(a, &value1);
  from_int_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_int(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

/*START_TEST(mul_test_25) {
  float a = 89.765786f;
  float b = 12.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_26) {
  float a = 89.765786f;
  float b = -12.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_27) {
  float a = -89.765786f;
  float b = 12.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_28) {
  float a = -89.765786f;
  float b = -12.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_29) {
  float a = 0;
  float b = 12.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_30) {
  float a = 0;
  float b = -12.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_31) {
  float a = 89.765786f;
  float b = 0;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = mul(result, &mul);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_32) {
  float a = -89.765786f;
  float b = 0;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = mul(result, &mul);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}

START_TEST(mul_test_33) {
  float a = 12.235681f;
  float b = 89.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_34) {
  float a = 12.235681f;
  float b = -89.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_35) {
  float a = -12.235681f;
  float b = 89.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_36) {
  float a = -12.235681f;
  float b = -89.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_37) {
  float a = 89565465.765786f;
  float b = 12455443.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_38) {
  float a = 89565465.765786f;
  float b = -12455443.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_39) {
  float a = -89565465.765786f;
  float b = 12455443.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_40) {
  float a = -89565465.765786f;
  float b = -12455443.235681f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_41) {
  float a = 12455443.235681f;
  float b = 89565465.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_42) {
  float a = 12455443.235681f;
  float b = -89565465.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = mul(value1, value2, &result);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_43) {
  float a = -12455443.235681f;
  float b = 89565465.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = from_decimal_to_int(result, &mul);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_44) {
  float a = -12455443.235681f;
  float b = -89565465.765786f;
  float mul;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  mul(value1, value2, &result);
  int code = from_decimal_to_int(result, &mul);
  from_decimal_to_float(result, &mul);
  ck_assert_int_eq(mul, a * b);
  ck_assert_int_eq(code, 0);
}*/

START_TEST(mul_test_45) {
  decimal value1;  // value1 = 79228162514264337593543950335
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;  // value2 = 0.6
  value2.bits[3] = 0b00000000000000010000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal expected;  // expected = 47536897508558602556126370201
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b10011001100110011001100110011001;
  expected.bits[1] = 0b10011001100110011001100110011001;
  expected.bits[0] = 0b10011001100110011001100110011001;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_46) {
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

  decimal expected;  // expected = -47536897508558602556126370201
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b10011001100110011001100110011001;
  expected.bits[1] = 0b10011001100110011001100110011001;
  expected.bits[0] = 0b10011001100110011001100110011001;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_47) {
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

  decimal expected;  // expected = 47536897508558602556126370200
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b10011001100110011001100110011001;
  expected.bits[1] = 0b10011001100110011001100110011001;
  expected.bits[0] = 0b10011001100110011001100110011000;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_48) {
  decimal value1;  // value1 = 45473458277750
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 1118159217325
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 50846566516909982462018750
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_49) {
  decimal value1;  // value1 = 45473458277750
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = -1118159217325
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = -50846566516909982462018750
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_50) {
  decimal value1;  // value1 = -45473458277750
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 1118159217325
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 50846566516909982462018750
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_51) {
  decimal value1;  // value1 = -45473458277750
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = -1118159217325
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 50846566516909982462018750
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_52) {
  decimal value1;  // value1 = 0
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[0] = 0b00000000000000000000000000000000;

  decimal value2;  // value2 = 1118159217325
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 0
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_53) {
  decimal value1;  // value1 = 0
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[0] = 0b00000000000000000000000000000000;

  decimal value2;  // value2 = -1118159217325
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = -0
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_54) {
  decimal value1;  // value1 = 45473458277750
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 0
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000000;

  decimal expected;  // expected = 0
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_55) {
  decimal value1;  // value1 = -45473458277750
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 0
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000000;

  decimal expected;  // expected = -0
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_56) {
  decimal value1;  // value1 = 45473458277.750
  value1.bits[3] = 0b00000000000000110000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 111815921732.5
  value2.bits[3] = 0b00000000000000010000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 5084656651690998246201.8750
  expected.bits[3] = 0b00000000000001000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_57) {
  decimal value1;  // value1 = 4547345827775.0
  value1.bits[3] = 0b00000000000000010000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 1118159217.325
  value2.bits[3] = 0b00000000000000110000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 5084656651690998246201.8750
  expected.bits[3] = 0b00000000000001000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_58) {
  decimal value1;  // value1 = 454734.58277750
  value1.bits[3] = 0b00000000000010000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 1.118159217325
  value2.bits[3] = 0b00000000000011000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 508465.66516909982462018750
  expected.bits[3] = 0b00000000000101000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_59) {
  decimal value1;  // value1 = 45.473458277750
  value1.bits[3] = 0b00000000000011000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 111815921.7325
  value2.bits[3] = 0b00000000000001000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 5084656651.6909982462018750
  expected.bits[3] = 0b00000000000100000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_60) {
  decimal value1;  // value1 = -45473458277.750
  value1.bits[3] = 0b10000000000000110000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 111815921732.5
  value2.bits[3] = 0b00000000000000010000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = -5084656651690998246201.8750
  expected.bits[3] = 0b10000000000001000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_61) {
  decimal value1;  // value1 = 4547345827775.0
  value1.bits[3] = 0b00000000000000010000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = -1118159217.325
  value2.bits[3] = 0b10000000000000110000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = -5084656651690998246201.8750
  expected.bits[3] = 0b10000000000001000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_62) {
  decimal value1;  // value1 = -454734.58277750
  value1.bits[3] = 0b10000000000010000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 1.118159217325
  value2.bits[3] = 0b00000000000011000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 508465.66516909982462018750
  expected.bits[3] = 0b10000000000101000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_63) {
  decimal value1;  // value1 = -45.473458277750
  value1.bits[3] = 0b10000000000011000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = -111815921.7325
  value2.bits[3] = 0b10000000000001000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 5084656651.6909982462018750
  expected.bits[3] = 0b00000000000100000000000000000000;
  expected.bits[2] = 0b00000000001010100000111100101101;
  expected.bits[1] = 0b11100100111000001010101001100111;
  expected.bits[0] = 0b00101011010110001000010010111110;

  decimal result;
  init_by_zeroes(&result);

  int code = mul(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_test_64) {  // positive overflow
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

  int code = mul(value1, value2, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(mul_test_65) {  // negative overflow
  decimal value1;
  value1.bits[3] = 0b10000000000000000000000000000000;
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

  int code = mul(value1, value2, &result);

  ck_assert_int_eq(code, 2);
}
END_TEST

Suite *test_mul(void) {
  Suite *suite = suite_create("test_mul");
  TCase *tc = tcase_create("test_mul");

  suite_add_tcase(suite, tc);

  tcase_add_test(tc, mul_test_0);
  tcase_add_test(tc, mul_test_1);
  tcase_add_test(tc, mul_test_2);
  tcase_add_test(tc, mul_test_3);
  tcase_add_test(tc, mul_test_4);
  tcase_add_test(tc, mul_test_5);
  tcase_add_test(tc, mul_test_6);
  tcase_add_test(tc, mul_test_7);
  tcase_add_test(tc, mul_test_8);
  tcase_add_test(tc, mul_test_9);
  tcase_add_test(tc, mul_test_10);
  tcase_add_test(tc, mul_test_11);
  tcase_add_test(tc, mul_test_12);
  tcase_add_test(tc, mul_test_13);
  tcase_add_test(tc, mul_test_14);
  tcase_add_test(tc, mul_test_15);
  tcase_add_test(tc, mul_test_16);
  tcase_add_test(tc, mul_test_17);
  tcase_add_test(tc, mul_test_18);
  tcase_add_test(tc, mul_test_19);
  tcase_add_test(tc, mul_test_20);
  tcase_add_test(tc, mul_test_21);
  tcase_add_test(tc, mul_test_22);
  tcase_add_test(tc, mul_test_23);
  tcase_add_test(tc, mul_test_24);
  /*tcase_add_test(tc, mul_test_25);
  tcase_add_test(tc, mul_test_26);
  tcase_add_test(tc, mul_test_27);
  tcase_add_test(tc, mul_test_28);
  tcase_add_test(tc, mul_test_29);
  tcase_add_test(tc, mul_test_30);
  tcase_add_test(tc, mul_test_31);
  tcase_add_test(tc, mul_test_32);
  tcase_add_test(tc, mul_test_33);
  tcase_add_test(tc, mul_test_34);
  tcase_add_test(tc, mul_test_35);
  tcase_add_test(tc, mul_test_36);
  tcase_add_test(tc, mul_test_37);
  tcase_add_test(tc, mul_test_38);
  tcase_add_test(tc, mul_test_39);
  tcase_add_test(tc, mul_test_40);
  tcase_add_test(tc, mul_test_41);
  tcase_add_test(tc, mul_test_42);
  tcase_add_test(tc, mul_test_43);
  tcase_add_test(tc, mul_test_44);*/
  tcase_add_test(tc, mul_test_45);
  tcase_add_test(tc, mul_test_46);
  tcase_add_test(tc, mul_test_47);
  tcase_add_test(tc, mul_test_48);
  tcase_add_test(tc, mul_test_49);
  tcase_add_test(tc, mul_test_50);
  tcase_add_test(tc, mul_test_51);
  tcase_add_test(tc, mul_test_52);
  tcase_add_test(tc, mul_test_53);
  tcase_add_test(tc, mul_test_54);
  tcase_add_test(tc, mul_test_55);
  tcase_add_test(tc, mul_test_56);
  tcase_add_test(tc, mul_test_57);
  tcase_add_test(tc, mul_test_58);
  tcase_add_test(tc, mul_test_59);
  tcase_add_test(tc, mul_test_60);
  tcase_add_test(tc, mul_test_61);
  tcase_add_test(tc, mul_test_62);
  tcase_add_test(tc, mul_test_63);
  tcase_add_test(tc, mul_test_64);
  tcase_add_test(tc, mul_test_65);

  return suite;

}
