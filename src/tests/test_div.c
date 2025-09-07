#include "test.h"

START_TEST(div_test_1) {
  float a = 89.765786f;
  float b = 12.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_2) {
  float a = 89.765786f;
  float b = -12.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_3) {
  float a = -89.765786f;
  float b = 12.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_4) {
  float a = -89.765786f;
  float b = -12.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_5) {
  float a = 0;
  float b = 12.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_6) {
  float a = 0;
  float b = -12.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_7) {
  float a = 89.765786f;
  float b = 0;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(code, 3);
}
END_TEST

START_TEST(div_test_8) {
  float a = -89.765786f;
  float b = 0;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(code, 3);
}

START_TEST(div_test_9) {
  float a = 12.235681f;
  float b = 89.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_10) {
  float a = 12.235681f;
  float b = -89.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_11) {
  float a = -12.235681f;
  float b = 89.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_12) {
  float a = -12.235681f;
  float b = -89.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_13) {
  float a = 89565465.765786f;
  float b = 12455443.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_14) {
  float a = 89565465.765786f;
  float b = -12455443.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_15) {
  float a = -89565465.765786f;
  float b = 12455443.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_16) {
  float a = -89565465.765786f;
  float b = -12455443.235681f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_17) {
  float a = 12455443.235681f;
  float b = 89565465.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_18) {
  float a = 12455443.235681f;
  float b = -89565465.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  int code = div(value1, value2, &result);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_19) {
  float a = -12455443.235681f;
  float b = 89565465.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  div(value1, value2, &result);
  int code = from_decimal_to_float(result, &div);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_20) {
  float a = -12455443.235681f;
  float b = -89565465.765786f;
  float div;
  decimal value1;
  decimal value2;
  decimal result;
  from_float_to_decimal(a, &value1);
  from_float_to_decimal(b, &value2);
  div(value1, value2, &result);
  int code = from_decimal_to_float(result, &div);
  from_decimal_to_float(result, &div);
  ck_assert_int_eq(div, a / b);
  ck_assert_int_eq(code, 0);
}

START_TEST(div_test_21) {
  decimal value1;  // value1 = 79228162514264337593543950335
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;  // value2 = 6
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal expected;  // expected = 13204693752377389598923991722
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00101010101010101010101010101010;
  expected.bits[1] = 0b10101010101010101010101010101010;
  expected.bits[0] = 0b10101010101010101010101010101010;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_22) {
  decimal value1;  // value1 = -79228162514264337593543950335
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;  // value2 = 6
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal expected;  // expected = -13204693752377389598923991722
  expected.bits[3] = 0b10000000000000000000000000000000;
  expected.bits[2] = 0b00101010101010101010101010101010;
  expected.bits[1] = 0b10101010101010101010101010101010;
  expected.bits[0] = 0b10101010101010101010101010101010;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_23) {
  decimal value1;  // value1 = -79228162514264337593543950335
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;  // value2 = 6
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal expected;  // expected = -13204693752377389598923991722
  expected.bits[3] = 0b00000000000000000000000000000000;
  expected.bits[2] = 0b00101010101010101010101010101010;
  expected.bits[1] = 0b10101010101010101010101010101010;
  expected.bits[0] = 0b10101010101010101010101010101010;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_24) {
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

  decimal expected;  // expected = 40.668142401524248866880841638
  expected.bits[3] = 0b00000000000110110000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_25) {
  decimal value1;  // value1 = 45473458277750
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 1118159217325
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 40.668142401524248866880841638
  expected.bits[3] = 0b10000000000110110000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_26) {
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

  decimal expected;  // expected = 40.6681424015242489
  expected.bits[3] = 0b10000000000110110000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_27) {
  decimal value1;  // value1 = 45473458277750
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000010100101011011;
  value1.bits[0] = 0b10011101010100111100110101110110;

  decimal value2;  // value2 = 1118159217325
  value2.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000100000100;
  value2.bits[0] = 0b01010111011110111010001010101101;

  decimal expected;  // expected = 40.6681424015242489
  expected.bits[3] = 0b00000000000110110000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_28) {
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
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000000;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_29) {
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

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_30) {
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

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(code, 3);
}
END_TEST

START_TEST(div_test_31) {
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

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(code, 3);
}
END_TEST

START_TEST(div_test_32) {
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

  decimal expected;  // expected = 0.4066814240152424886688084163
  expected.bits[3] = 0b00000000000111000000000000000000;
  expected.bits[2] = 0b00001101001000111111110101101001;
  expected.bits[1] = 0b10110110101000100010111101101110;
  expected.bits[0] = 0b01101010011110001111000011000011;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_33) {
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

  decimal expected;  // expected = 4066.8142401524248866880841638
  expected.bits[3] = 0b00000000000110010000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_34) {
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

  decimal expected;  // expected = 406681.42401524248866880841638
  expected.bits[3] = 0b00000000000101110000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_35) {
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

  decimal expected;  // expected = 0.000000406681424
  expected.bits[3] = 0b00000000000111000000000000000000;
  expected.bits[2] = 0b00000000000000000000000011011100;
  expected.bits[1] = 0b01110110011000101001010010000011;
  expected.bits[0] = 0b01101001011011010011000110100000;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_36) {
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

  decimal expected;  // expected = 0.4066814240152424886688084163
  expected.bits[3] = 0b10000000000111000000000000000000;
  expected.bits[2] = 0b00001101001000111111110101101001;
  expected.bits[1] = 0b10110110101000100010111101101110;
  expected.bits[0] = 0b01101010011110001111000011000011;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_37) {
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

  decimal expected;  // expected = -4066.8142401524248866880841638
  expected.bits[3] = 0b10000000000110010000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_38) {
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

  decimal expected;  // expected = -406681.42401524248866880841638
  expected.bits[3] = 0b10000000000101110000000000000000;
  expected.bits[2] = 0b10000011011001111110011000100001;
  expected.bits[1] = 0b00100010010101011101101001010000;
  expected.bits[0] = 0b00101000101110010110011110100110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_39) {
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

  decimal expected;  // expected = 0.0000004066814240152424886688
  expected.bits[3] = 0b00000000000111000000000000000000;
  expected.bits[2] = 0b00000000000000000000000011011100;
  expected.bits[1] = 0b01110110011000101001010010000011;
  expected.bits[0] = 0b01101001011011010011000110100000;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_test_40) {  // positive overflow
  decimal value1;          // value1 = 79228162514264337593543950335
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;  // value2 = 0.006
  value2.bits[3] = 0b00000000000000100000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(div_test_41) {  // negative overflow
  decimal value1;
  value1.bits[3] = 0b10000000000000000000000000000000;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[0] = 0b11111111111111111111111111111111;

  decimal value2;
  value2.bits[3] = 0b00000000000000100000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000110;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(div_test_42) {
  decimal value1;  // value1 = 1
  value1.bits[3] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[0] = 0b00000000000000000000000000000001;

  decimal value2;  // value2 = 2
  value2.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b00000000000000000000000000000010;

  decimal expected;  // expected = 5
  expected.bits[3] = 0b00000000000000010000000000000000;
  expected.bits[2] = 0b00000000000000000000000000000000;
  expected.bits[1] = 0b00000000000000000000000000000000;
  expected.bits[0] = 0b00000000000000000000000000000101;

  decimal result;
  init_by_zeroes(&result);

  int code = div(value1, value2, &result);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *test_div(void) {
  Suite *suite = suite_create("test_div");
  TCase *tc = tcase_create("test_div");
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, div_test_1);
  tcase_add_test(tc, div_test_2);
  tcase_add_test(tc, div_test_3);
  tcase_add_test(tc, div_test_4);
  tcase_add_test(tc, div_test_5);
  tcase_add_test(tc, div_test_6);
  tcase_add_test(tc, div_test_7);
  tcase_add_test(tc, div_test_8);
  tcase_add_test(tc, div_test_9);
  tcase_add_test(tc, div_test_10);
  tcase_add_test(tc, div_test_11);
  tcase_add_test(tc, div_test_12);
  tcase_add_test(tc, div_test_13);
  tcase_add_test(tc, div_test_14);
  tcase_add_test(tc, div_test_15);
  tcase_add_test(tc, div_test_16);
  tcase_add_test(tc, div_test_17);
  tcase_add_test(tc, div_test_18);
  tcase_add_test(tc, div_test_19);
  tcase_add_test(tc, div_test_20);
  tcase_add_test(tc, div_test_21);
  tcase_add_test(tc, div_test_22);
  tcase_add_test(tc, div_test_23);
  tcase_add_test(tc, div_test_24);
  tcase_add_test(tc, div_test_25);
  tcase_add_test(tc, div_test_26);
  tcase_add_test(tc, div_test_27);
  tcase_add_test(tc, div_test_28);
  tcase_add_test(tc, div_test_29);
  tcase_add_test(tc, div_test_30);
  tcase_add_test(tc, div_test_31);
  tcase_add_test(tc, div_test_32);
  tcase_add_test(tc, div_test_33);
  tcase_add_test(tc, div_test_34);
  tcase_add_test(tc, div_test_35);
  tcase_add_test(tc, div_test_36);
  tcase_add_test(tc, div_test_37);
  tcase_add_test(tc, div_test_38);
  tcase_add_test(tc, div_test_39);
  tcase_add_test(tc, div_test_40);
  tcase_add_test(tc, div_test_41);
  tcase_add_test(tc, div_test_42);

  return suite;

}
