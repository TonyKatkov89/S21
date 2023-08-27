#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

#define TEST_EPS 1e-6

START_TEST(test_abs) {
  int x;

  for (x = -5468; x < 5468; ++x) {
    ck_assert_ldouble_eq(s21_abs(x), abs(x));
  }
  for (x = -1365867877; x < 1365867877; x += 28364265) {
    ck_assert_int_eq(s21_abs(x), abs(x));
  }
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(test_fabs) {
  double x;

  for (x = -13654687498.467687157; x < 13654687498.467687157;
       x += 91826354.9286868) {
    ck_assert_ldouble_eq_tol(s21_fabs(x), fabsl(x), 0.0000005);
  }
  for (x = -158.467687157; x < 158.467687157; x += 0.9286868) {
    ck_assert_ldouble_eq_tol(s21_fabs(x), fabsl(x), 0.0000005);
  }
  ck_assert_ldouble_eq(s21_fabs(0.0), fabsl(0.0));
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_eq(s21_fabs(INF), fabsl(INF));
  ck_assert_ldouble_eq(s21_fabs(-INF), fabsl(-INF));
}
END_TEST

START_TEST(test_ceil) {
  double x;

  for (x = -13654687498.467687157; x < 13654687498.467687157;
       x += 91826354.9286868) {
    ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
  }
  for (x = -158.467687157; x < 158.467687157; x += 0.9286868) {
    ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
  }
  ck_assert_ldouble_eq(s21_ceil(0.0), ceill(0.0));
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_eq(s21_ceil(INF), ceill(INF));
  ck_assert_ldouble_eq(s21_ceil(-INF), ceill(-INF));
}
END_TEST

Suite *MathSuite(void);

START_TEST(test_floor) {
  double x;

  for (x = -13654687498.467687157; x < 13654687498.467687157;
       x += 91826354.9286868) {
    ck_assert_ldouble_eq(s21_floor(x), floorl(x));
  }
  for (x = -158.467687157; x < 158.467687157; x += 0.9286868) {
    ck_assert_ldouble_eq(s21_floor(x), floorl(x));
  }
  ck_assert_ldouble_eq(s21_floor(0.0), floorl(0.0));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_eq(s21_floor(INF), floorl(INF));
  ck_assert_ldouble_eq(s21_floor(-INF), floorl(-INF));
}
END_TEST

START_TEST(test_fmod) {
  double x;
  double y;

  for (x = -3654687498.467687157; x < 3654687498.467687157;
       x += 91826354.286868) {
    for (y = -654687498.467687157; y < 654687498.467687157;
         y += 91826354.286868) {
      ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), 0.0000005);
    }
  }
  for (x = -658.467687157; x < 658.467687157; x += 0.9286868) {
    for (y = -58.467687157; y < 58.467687157; y += 0.286868) {
      ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), 0.0000005);
    }
  }
  for (x = -58.467687157; x < 58.467687157; x += 0.9286868) {
    for (y = -358.467687157; y < 358.467687157; y += 0.286868) {
      ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), 0.0000005);
    }
  }
  ck_assert_ldouble_nan(s21_fmod(x, 0.0));
  ck_assert_ldouble_eq(s21_fmod(0.0, y), fmodl(0.0, y));
  ck_assert_ldouble_nan(s21_fmod(NAN, 2));
  ck_assert_ldouble_nan(s21_fmod(2.0, NAN));
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
  ck_assert_ldouble_nan(s21_fmod(INF, 2.0));
  ck_assert_ldouble_eq(s21_fmod(2.0, INF), fmodl(2.0, INF));
  ck_assert_ldouble_nan(s21_fmod(INF, INF));
  ck_assert_ldouble_nan(s21_fmod(-INF, -INF));
  ck_assert_ldouble_nan(s21_fmod(-INF, INF));
  ck_assert_ldouble_nan(s21_fmod(INF, -INF));
}
END_TEST

START_TEST(test_sin) {
  double x;

  for (x = -13654687498.467687157; x < 13654687498.467687157;
       x += 91826354.9286868) {
    ck_assert_ldouble_eq_tol(s21_sin(x), sinl(x), 0.000001);
  }
  for (x = -158.467687157; x < 158.467687157; x += 0.9286868) {
    ck_assert_ldouble_eq_tol(s21_sin(x), sinl(x), 0.000001);
  }
  ck_assert_ldouble_eq_tol(s21_sin(0.0), sinl(0.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(2 * S21_PI), sinl(2 * S21_PI), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(-2 * S21_PI), sinl(-2 * S21_PI), 0.000001);
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(s21_sin(INF));
  ck_assert_ldouble_nan(s21_sin(-INF));
}
END_TEST

START_TEST(test_cos) {
  double x;

  for (x = -13654687498.467687157; x < 13654687498.467687157;
       x += 91826354.9286868) {
    ck_assert_ldouble_eq_tol(s21_cos(x), cosl(x), 0.000001);
  }
  for (x = -158.467687157; x < 158.467687157; x += 0.9286868) {
    ck_assert_ldouble_eq_tol(s21_cos(x), cosl(x), 0.000001);
  }
  ck_assert_ldouble_eq_tol(s21_cos(0.0), cosl(0.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(2 * S21_PI), cosl(2 * S21_PI), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(-2 * S21_PI), cosl(-2 * S21_PI), 0.000001);
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INF));
  ck_assert_ldouble_nan(s21_cos(-INF));
}
END_TEST

START_TEST(test_tan) {
  double x;

  for (x = -687498.4676; x < 687498.4676; x += 26354.9286) {
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), 0.000001);
  }
  for (x = -8.4676; x < 8.4676; x += 0.358) {
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), 0.000001);
  }
  ck_assert_ldouble_eq_tol(s21_tan(0.0), tanl(0.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(2 * S21_PI), tanl(2 * S21_PI), 0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(-2 * S21_PI), tanl(-2 * S21_PI), 0.000001);
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(s21_tan(INF));
  ck_assert_ldouble_nan(s21_tan(-INF));
}
END_TEST

START_TEST(test_atan) {
  double x;

  for (x = -13654687498.467687157; x < 13654687498.467687157;
       x += 91826354.9286868) {
    ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  }
  for (x = -1.5; x < 1.5; x += 0.009286868) {
    ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 0.000001);
  }
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(2 * S21_PI), atanl(2 * S21_PI), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-2 * S21_PI), atanl(-2 * S21_PI), 0.000001);
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_eq_tol(s21_atan(INF), atan(INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-INF), atan(-INF), 0.000001);
}
END_TEST

START_TEST(test_asin) {
  double x;

  for (x = -1; x < 1; x += 0.009286868) {
    ck_assert_ldouble_eq_tol(s21_asin(x), asinl(x), 0.000001);
  }
  ck_assert_ldouble_eq_tol(s21_asin(0), asinl(0), 0.000001);
  ck_assert_ldouble_nan(s21_asin(2 * S21_PI));
  ck_assert_ldouble_nan(s21_asin(-2 * S21_PI));
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INF));
  ck_assert_ldouble_nan(s21_asin(-INF));
}
END_TEST

START_TEST(test_acos) {
  double x;

  for (x = -1; x < 1; x += 0.009286868) {
    ck_assert_ldouble_eq_tol(s21_acos(x), acosl(x), 0.000001);
  }
  ck_assert_ldouble_eq_tol(s21_acos(0), acosl(0), 0.000001);
  ck_assert_ldouble_nan(s21_acos(2 * S21_PI));
  ck_assert_ldouble_nan(s21_acos(-2 * S21_PI));
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(s21_acos(INF));
  ck_assert_ldouble_nan(s21_acos(-INF));
}
END_TEST

START_TEST(test_s21_exp_INF_NAN) {
  {  // NAN
    ck_assert_double_nan(exp(NAN));
    ck_assert_double_nan(s21_exp(NAN));
  }
  ck_assert_double_eq(exp(INF), s21_exp(INF));
  ck_assert_double_eq(exp(-INF), s21_exp(-INF));
}
END_TEST

START_TEST(test_s21_log_INF_NAN) {
  {  // NAN
    ck_assert_double_nan(log(NAN));
    ck_assert_double_nan(s21_log(NAN));

    ck_assert_double_nan(log(-INF));
    ck_assert_double_nan(s21_log(-INF));
  }
  ck_assert_double_eq(log(INF), s21_log(INF));
  ck_assert_double_eq(log(INF), s21_log(INF));
  {  // INF
    ck_assert_double_infinite(log(0.));
    ck_assert_double_infinite(s21_log(0.));
  }
}
END_TEST

START_TEST(test_s21_pow_INF_NAN) {
  {  // NAN
    ck_assert_double_nan(pow(NAN, NAN));
    ck_assert_double_nan(s21_pow(NAN, NAN));

    ck_assert_double_nan(pow(NAN, INF));
    ck_assert_double_nan(s21_pow(NAN, INF));

    ck_assert_double_nan(pow(NAN, -INF));
    ck_assert_double_nan(s21_pow(NAN, -INF));

    ck_assert_double_nan(pow(INF, NAN));
    ck_assert_double_nan(s21_pow(INF, NAN));

    ck_assert_double_nan(pow(-INF, NAN));
    ck_assert_double_nan(s21_pow(-INF, NAN));
  }
  ck_assert_double_eq(pow(INF, INF), s21_pow(INF, INF));
  ck_assert_double_eq(pow(INF, -INF), s21_pow(INF, -INF));

  ck_assert_double_eq(pow(-INF, INF), s21_pow(-INF, INF));
  ck_assert_double_eq(pow(-INF, -INF), s21_pow(-INF, -INF));
}
END_TEST

START_TEST(test_s21_pow_val_INF_NaN) {
  {  // NAN
    ck_assert_double_nan(pow(0, NAN));
    ck_assert_double_nan(s21_pow(0, NAN));

    ck_assert_double_nan(pow(-2, NAN));
    ck_assert_double_nan(s21_pow(-2, NAN));

    ck_assert_double_nan(pow(1 + 1e-15, NAN));
    ck_assert_double_nan(s21_pow(1 + 1e-15, NAN));
  }
  ck_assert_double_eq(pow(1 + 1e-16, NAN), s21_pow(1 + 1e-16, NAN));
  ck_assert_double_eq(pow(-10.0, INF), s21_pow(-10.0, INF));
  ck_assert_double_eq(pow(-1, INF), s21_pow(-1, INF));
  ck_assert_double_eq(pow(-0.5, INF), s21_pow(-0.5, INF));
  ck_assert_double_eq(pow(0, INF), s21_pow(0, INF));
  ck_assert_double_eq(pow(0.5, INF), s21_pow(0.5, INF));
  ck_assert_double_eq(pow(1, INF), s21_pow(1, INF));
  ck_assert_double_eq(pow(500, INF), s21_pow(500, INF));
  ck_assert_double_eq(pow(-10, -INF), s21_pow(-10, -INF));
  ck_assert_double_eq(pow(-1, -INF), s21_pow(-1, -INF));
  ck_assert_double_eq(pow(-0.5, -INF), s21_pow(-0.5, -INF));
  ck_assert_double_eq(pow(0, -INF), s21_pow(0, -INF));
  ck_assert_double_eq(pow(0.5, -INF), s21_pow(0.5, -INF));
  ck_assert_double_eq(pow(1, -INF), s21_pow(1, -INF));
  ck_assert_double_eq(pow(500, -INF), s21_pow(500, -INF));
  ck_assert_double_eq(pow(INF, -10), s21_pow(INF, -10));
  ck_assert_double_eq(pow(INF, -1), s21_pow(INF, -1));
  ck_assert_double_eq(pow(INF, -0.5), s21_pow(INF, -0.5));
  ck_assert_double_eq(pow(INF, 0), s21_pow(INF, 0));
  ck_assert_double_eq(pow(INF, 0.5), s21_pow(INF, 0.5));
  ck_assert_double_eq(pow(INF, 1), s21_pow(INF, 1));
  ck_assert_double_eq(pow(INF, 500), s21_pow(INF, 500));
  ck_assert_double_eq(pow(INF, -1), s21_pow(INF, -1));
  ck_assert_double_eq(pow(-INF, -10), s21_pow(-INF, -10));
  ck_assert_double_eq(pow(-INF, -0.5), s21_pow(-INF, -0.5));
  ck_assert_double_eq(pow(-INF, 0), s21_pow(-INF, 0));
  ck_assert_double_eq(pow(-INF, 0.5), s21_pow(-INF, 0.5));
  ck_assert_double_eq(pow(-INF, 1), s21_pow(-INF, 1));
  ck_assert_double_eq(pow(-INF, 500), s21_pow(-INF, 500));
}
END_TEST

START_TEST(test_s21_sqrt_INF_NAN) {
  {  // NAN
    ck_assert_double_nan(sqrt(NAN));
    ck_assert_double_nan(s21_sqrt(NAN));

    ck_assert_double_nan(sqrt(-INF));
    ck_assert_double_nan(s21_sqrt(-INF));
  }
  ck_assert_double_eq(sqrt(INF), s21_sqrt(INF));
}
END_TEST

START_TEST(test_normal_vals_s21_exp_val) {
  double i = -100;
  while (i < 28) {  // дальше точность должно уменьшиться, больше 11 знаков
    ck_assert_ldouble_eq_tol(expl(i), s21_exp(i), TEST_EPS);
    i += 0.1;
  }
}
END_TEST

START_TEST(test_normal_vals_s21_log_val) {
  double i = 0.1;
  while (i < 100) {  //готов
    ck_assert_ldouble_eq_tol(logl(i), s21_log(i), TEST_EPS);
    i += 0.1;
  }
  ck_assert_double_nan(s21_log(-1));
}
END_TEST

START_TEST(test_normal_vals_s21_pow_val) {
  double i = -25.128;
  while (i < 25.128) {  // дальше точность должно уменьшиться, больше 10 знаков
    ck_assert_ldouble_eq_tol(powl(2.5, i), s21_pow(2.5, i), TEST_EPS);
    i += 0.1423;
  }
}
END_TEST

START_TEST(test_normal_vals_s21_sqrt_val) {
  double i = 0.1;
  while (i < 100) {
    ck_assert_ldouble_eq_tol(sqrtl(i), s21_sqrt(i), TEST_EPS);
    i += 0.1;
  }
  ck_assert_double_nan(s21_sqrt(-1));
}
END_TEST

START_TEST(test_big_vals_s21_exp_val) {
  //совпавшие цифры
  ck_assert_ldouble_eq_tol(expl(29.5), s21_exp(29.5),
                           1e-3);  // 6481674477934.32021
  ck_assert_ldouble_eq_tol(expl(32.234), s21_exp(32.234),
                           1e-3);                         // 99781109723266.6999
  ck_assert_ldouble_eq_tol(expl(50), s21_exp(50), 1e+3);  // 5184705528587072463
  ck_assert_ldouble_eq_tol(expl(54.345), s21_exp(54.345),
                           1e+6);  // 399699512928979106
  ck_assert_ldouble_eq_tol(expl(67), s21_exp(67),
                           1e+11);  // 1252363170842213780
  ck_assert_ldouble_eq_tol(expl(102.543), s21_exp(102.543),
                           1e+26);  // 341868477454341510
  ck_assert_ldouble_eq_tol(expl(200), s21_exp(200),
                           1e+69);  // 722597376812574925
  ck_assert_ldouble_eq_tol(expl(500), s21_exp(500),
                           1e+199);  // 140359221785283741
}
END_TEST

START_TEST(test_big_vals_s21_log_val) {
  //совпавшие цифры
  ck_assert_ldouble_eq_tol(logl(1000000.23423), s21_log(1000000.23423),
                           1e-6);  // 13.81551079219424
  ck_assert_ldouble_eq_tol(logl(1432343234.23423), s21_log(1432343234.23423),
                           1e-6);  // 21.0825775654751
  ck_assert_ldouble_eq_tol(logl(1e+12), s21_log(1e+12),
                           1e-6);  // 27.63102111592854
  ck_assert_ldouble_eq_tol(logl(1e+24), s21_log(1e+24),
                           1e-6);  // 55.26204223185709
  ck_assert_ldouble_eq_tol(logl(1e+100), s21_log(1e+100),
                           1e-6);  // 230.2585092994045
  ck_assert_ldouble_eq_tol(logl(1e+300), s21_log(1e+300),
                           1e-6);  // 690.7755278982137
  ck_assert_ldouble_eq_tol(logl(1e+308), s21_log(1e+308),
                           1e-6);  // 709.196208642166
}
END_TEST

START_TEST(test_big_vals_s21_pow_val) {
  //совпавшие цифры
  ck_assert_ldouble_eq_tol(powl(1.5, 50.9), s21_pow(1.5, 50.9),
                           1e-6);  // 780923662.27616823
  ck_assert_ldouble_eq_tol(powl(5.3, 30.9), s21_pow(5.3, 30.9),
                           1e+8);  // 239951998086217
  ck_assert_ldouble_eq_tol(powl(2, 200), s21_pow(2, 200),
                           1e-6);  // 16069380442589902755419
  ck_assert_ldouble_eq_tol(powl(2.5, 300.5), s21_pow(2.5, 300.5),
                           1e+105);  // 2409919865102885
  ck_assert_ldouble_eq_tol(powl(10.5, 20), s21_pow(10.5, 20),
                           1e+4);  // 26532977051444201
}
END_TEST

START_TEST(test_big_vals_s21_sqrt_val) {
  //совпавшие цифры
  ck_assert_ldouble_eq_tol(sqrtl(1e+21), s21_sqrt(1e+21),
                           1e-6);  // 31622776601.6837933
  ck_assert_ldouble_eq_tol(sqrtl(1e+41), s21_sqrt(1e+41),
                           1e-6);  // 316227766016837934176
  ck_assert_ldouble_eq_tol(sqrtl(1e+141), s21_sqrt(1e+141),
                           1e-6);  // 10000000000000000254191711213
  ck_assert_ldouble_eq_tol(sqrtl(1e+306), s21_sqrt(1e+306),
                           1e-6);  // 100000000000000000863717737674
}
END_TEST

Suite *MathSuite(void);

Suite *NaN_INF_SuiteCreate(void);

Suite *NormalValsSuiteCreate(void);

Suite *BigVals_exp_SuiteCreate(void);

Suite *BigVals_log_SuiteCreate(void);

Suite *BigVals_pow_SuiteCreate(void);

Suite *BigVals_sqrt_SuiteCreate(void);

int main(void) {
  int no_failed = 0;
  Suite *s = MathSuite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  Suite *suite = NaN_INF_SuiteCreate();
  SRunner *suite_runner = srunner_create(suite);

  Suite *suite_norm_val = NormalValsSuiteCreate();
  SRunner *suite_runner_norm_val = srunner_create(suite_norm_val);

  Suite *suite_big_vals_exp = BigVals_exp_SuiteCreate();
  SRunner *suite_runner_big_vals_exp = srunner_create(suite_big_vals_exp);

  Suite *suite_big_vals_log = BigVals_log_SuiteCreate();
  SRunner *suite_runner_big_vals_log = srunner_create(suite_big_vals_log);

  Suite *suite_big_vals_pow = BigVals_pow_SuiteCreate();
  SRunner *suite_runner_big_vals_pow = srunner_create(suite_big_vals_pow);

  Suite *suite_big_vals_sqrt = BigVals_sqrt_SuiteCreate();
  SRunner *suite_runner_big_vals_sqrt = srunner_create(suite_big_vals_sqrt);

  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_run_all(suite_runner_norm_val, CK_NORMAL);
  srunner_run_all(suite_runner_big_vals_exp, CK_NORMAL);
  srunner_run_all(suite_runner_big_vals_log, CK_NORMAL);
  srunner_run_all(suite_runner_big_vals_pow, CK_NORMAL);
  srunner_run_all(suite_runner_big_vals_sqrt, CK_NORMAL);
  // Получаем количество проваленных тестов.
  int failed_count = srunner_ntests_failed(suite_runner);
  failed_count += srunner_ntests_failed(suite_runner_norm_val);
  failed_count += srunner_ntests_failed(suite_runner_big_vals_exp);
  failed_count += srunner_ntests_failed(suite_runner_big_vals_log);
  failed_count += srunner_ntests_failed(suite_runner_big_vals_pow);
  failed_count += srunner_ntests_failed(suite_runner_big_vals_sqrt);
  srunner_free(suite_runner);
  srunner_free(suite_runner_norm_val);
  srunner_free(suite_runner_big_vals_exp);
  srunner_free(suite_runner_big_vals_log);
  srunner_free(suite_runner_big_vals_pow);
  srunner_free(suite_runner_big_vals_sqrt);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    // printf("\n\nFail %d tests!\n\n", failed_count);
  }

  return no_failed;
}

Suite *MathSuite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("Math");
  tc = tcase_create("abs");
  tcase_add_test(tc, test_abs);
  suite_add_tcase(s, tc);
  tc = tcase_create("fabsl");
  tcase_add_test(tc, test_fabs);
  suite_add_tcase(s, tc);
  tc = tcase_create("ceill");
  tcase_add_test(tc, test_ceil);
  suite_add_tcase(s, tc);
  tc = tcase_create("floorl");
  tcase_add_test(tc, test_floor);
  suite_add_tcase(s, tc);
  tc = tcase_create("fmodl");
  tcase_add_test(tc, test_fmod);
  suite_add_tcase(s, tc);
  tc = tcase_create("sinl");
  tcase_add_test(tc, test_sin);
  suite_add_tcase(s, tc);
  tc = tcase_create("cosl");
  tcase_add_test(tc, test_cos);
  suite_add_tcase(s, tc);
  tc = tcase_create("tanl");
  tcase_add_test(tc, test_tan);
  suite_add_tcase(s, tc);
  tc = tcase_create("atan");
  tcase_add_test(tc, test_atan);
  suite_add_tcase(s, tc);
  tc = tcase_create("asinl");
  tcase_add_test(tc, test_asin);
  suite_add_tcase(s, tc);
  tc = tcase_create("acosl");
  tcase_add_test(tc, test_acos);
  suite_add_tcase(s, tc);

  return s;
}

Suite *NaN_INF_SuiteCreate(void) {
  Suite *suite = suite_create("NAN INF");
  TCase *tcase_core = tcase_create("Core of NAN INF");

  tcase_add_test(tcase_core, test_s21_exp_INF_NAN);
  tcase_add_test(tcase_core, test_s21_log_INF_NAN);
  tcase_add_test(tcase_core, test_s21_pow_INF_NAN);
  tcase_add_test(tcase_core, test_s21_pow_val_INF_NaN);
  tcase_add_test(tcase_core, test_s21_sqrt_INF_NAN);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

Suite *NormalValsSuiteCreate(void) {
  Suite *suite = suite_create("Normal Vals");
  TCase *tcase_core = tcase_create("Core of Normal Val");

  tcase_add_test(tcase_core, test_normal_vals_s21_exp_val);
  tcase_add_test(tcase_core, test_normal_vals_s21_log_val);
  tcase_add_test(tcase_core, test_normal_vals_s21_pow_val);
  tcase_add_test(tcase_core, test_normal_vals_s21_sqrt_val);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

Suite *BigVals_exp_SuiteCreate(void) {
  Suite *suite = suite_create("Big vals s21_exp");
  TCase *tcase_core = tcase_create("Core of Big vals s21_exp");

  tcase_add_test(tcase_core, test_big_vals_s21_exp_val);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

Suite *BigVals_log_SuiteCreate(void) {
  Suite *suite = suite_create("Big vals s21_log");
  TCase *tcase_core = tcase_create("Core of Big vals s21_log");
  tcase_add_test(tcase_core, test_big_vals_s21_log_val);
  suite_add_tcase(suite, tcase_core);

  return suite;
}

Suite *BigVals_pow_SuiteCreate(void) {
  Suite *suite = suite_create("Big vals s21_pow");
  TCase *tcase_core = tcase_create("Core of Big vals s21_pow");
  tcase_add_test(tcase_core, test_big_vals_s21_pow_val);
  suite_add_tcase(suite, tcase_core);

  return suite;
}

Suite *BigVals_sqrt_SuiteCreate(void) {
  Suite *suite = suite_create("Big vals s21_sqrt");
  TCase *tcase_core = tcase_create("Core of Big vals s21_sqrt");
  tcase_add_test(tcase_core, test_big_vals_s21_sqrt_val);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
