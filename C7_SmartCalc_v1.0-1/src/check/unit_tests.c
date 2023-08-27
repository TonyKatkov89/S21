#include "unit_tests.h"

START_TEST(s21_eq_calculator_test_1) {
  char input[MAX_SIZE] = "((3+2)-x)^2";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 9., 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_2) {
  char input[MAX_SIZE] = "tan2x*sinx^2";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, -0.8762420356, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_3) {
  char input[MAX_SIZE] = "5/0";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_nan(result);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_4) {
  char input[MAX_SIZE] = "tn2x*sinx^2";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_nan(result);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_5) {
  char input[MAX_SIZE] = "+some shit";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_nan(result);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_6) {
  char input[MAX_SIZE] = "cos(-2*5^6.412)*2.6x^3";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, -13.9485561566, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_7) {
  char input[MAX_SIZE] = "acos(cosx)";
  double x = 0.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 0.5, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_8) {
  char input[MAX_SIZE] = "atan(tanx)";
  double x = 0.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 0.5, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_9) {
  char input[MAX_SIZE] = "ctgx";
  double x = 0.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 1.83048772171, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_10) {
  char input[MAX_SIZE] = "asin(sinx)/2";
  double x = 0.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 0.25, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_11) {
  char input[MAX_SIZE] = "log(ln(xmod1+1)";
  double x = 3.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, -0.39204651261, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_12) {
  char input[MAX_SIZE] = "sqrt(+x)";
  double x = 3.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 1.87082869339, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_13) {
  char input[MAX_SIZE] = "sqrt(-x)";
  double x = 3.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_nan(result);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_14) {
  char input[MAX_SIZE] = "mod0";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_nan(result);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_15) {
  char input[MAX_SIZE * 2] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  double x = 3.5;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 128, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_16) {
  char input[MAX_SIZE] = "5+2$";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_nan(result);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

START_TEST(s21_eq_calculator_test_17) {
  double s = 12000000;
  double p = 5.5 / 100;
  double n = 360;
  double result = annuity_payment(s, p, n);
  ck_assert_double_eq_tol(result, 68134.68, 0.005);
}
END_TEST

START_TEST(s21_eq_calculator_test_18) {
  double s = 60000;
  double p = 5.5 / 100;
  double result = interest_sum(s, p);
  ck_assert_double_eq_tol(result, 275, 0.005);
}
END_TEST

START_TEST(s21_eq_calculator_test_19) {
  double s = 12000000;
  double p = 0;
  double n = 300;
  double result = annuity_payment(s, p, n);
  ck_assert_double_eq_tol(result, 40000, 0.005);
}
END_TEST

START_TEST(s21_eq_calculator_test_20) {
  char input[MAX_SIZE] = "x+2";
  double x = 2.;
  stack_s *notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, x);
  double result = calculate(reversed_notation);
  ck_assert_double_eq_tol(result, 4, 0.00000005);
  free_stack(notation);
  free_stack(reversed_notation);
}
END_TEST

void srunner_add_calculator_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Calculator");
  TCase *tc1_1 = tcase_create("Calculator");
  suite_add_tcase(save_v1, tc1_1);
  tcase_add_test(tc1_1, s21_eq_calculator_test_1);
  tcase_add_test(tc1_1, s21_eq_calculator_test_2);
  tcase_add_test(tc1_1, s21_eq_calculator_test_3);
  tcase_add_test(tc1_1, s21_eq_calculator_test_4);
  tcase_add_test(tc1_1, s21_eq_calculator_test_5);
  tcase_add_test(tc1_1, s21_eq_calculator_test_6);
  tcase_add_test(tc1_1, s21_eq_calculator_test_7);
  tcase_add_test(tc1_1, s21_eq_calculator_test_8);
  tcase_add_test(tc1_1, s21_eq_calculator_test_9);
  tcase_add_test(tc1_1, s21_eq_calculator_test_10);
  tcase_add_test(tc1_1, s21_eq_calculator_test_11);
  tcase_add_test(tc1_1, s21_eq_calculator_test_12);
  tcase_add_test(tc1_1, s21_eq_calculator_test_13);
  tcase_add_test(tc1_1, s21_eq_calculator_test_14);
  tcase_add_test(tc1_1, s21_eq_calculator_test_15);
  tcase_add_test(tc1_1, s21_eq_calculator_test_16);
  tcase_add_test(tc1_1, s21_eq_calculator_test_17);
  tcase_add_test(tc1_1, s21_eq_calculator_test_18);
  tcase_add_test(tc1_1, s21_eq_calculator_test_19);
  tcase_add_test(tc1_1, s21_eq_calculator_test_20);

  srunner_add_suite(sr, save_v1);
}

int main(void) {
  Suite *s = suite_create("Calculator tests");
  SRunner *sr = srunner_create(s);
  int nf;

  srunner_add_calculator_tests(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}