#include "unit_tests.h"

void fill_in_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = i * pow(-1, j) + (j * 1.2) - i * j - 1.7 * pow(-1, i);
    }
  }
}

void fill_in_sum_mul_check(matrix_t *A) {
  A->matrix[0][0] = -3.4;
  A->matrix[0][1] = -1;
  A->matrix[0][2] = 1.4;
  A->matrix[0][3] = 3.8;
  A->matrix[1][0] = 5.4;
  A->matrix[1][1] = 1.8;
  A->matrix[1][2] = 6.2;
  A->matrix[1][3] = 2.6;
  A->matrix[2][0] = 0.6;
  A->matrix[2][1] = -9;
  A->matrix[2][2] = -2.6;
  A->matrix[2][3] = -12.2;
  A->matrix[3][0] = 9.4;
  A->matrix[3][1] = -6.2;
  A->matrix[3][2] = 2.2;
  A->matrix[3][3] = -13.4;
}

void fill_in_mat_mul_check(matrix_t *A) {
  A->matrix[0][0] = 1.75;
  A->matrix[0][1] = -2.75;
  A->matrix[0][2] = -3.65;
  A->matrix[0][3] = -8.15;
  A->matrix[1][0] = -1.23;
  A->matrix[1][1] = -14.49;
  A->matrix[1][2] = 0.65;
  A->matrix[1][3] = -12.61;
  A->matrix[2][0] = -13.05;
  A->matrix[2][1] = 1.65;
  A->matrix[2][2] = -12.05;
  A->matrix[2][3] = 2.65;
  A->matrix[3][0] = -16.03;
  A->matrix[3][1] = -10.09;
  A->matrix[3][2] = -7.75;
  A->matrix[3][3] = -1.81;
}

void fill_in_transpose_check(matrix_t *A) {
  A->matrix[0][0] = -1.7;
  A->matrix[0][1] = 2.7;
  A->matrix[0][2] = 0.3;
  A->matrix[0][3] = 4.7;
  A->matrix[1][0] = -0.5;
  A->matrix[1][1] = 0.9;
  A->matrix[1][2] = -4.5;
  A->matrix[1][3] = -3.1;
  A->matrix[2][0] = 0.7;
  A->matrix[2][1] = 3.1;
  A->matrix[2][2] = -1.3;
  A->matrix[2][3] = 1.1;
  A->matrix[3][0] = 1.9;
  A->matrix[3][1] = 1.3;
  A->matrix[3][2] = -6.1;
  A->matrix[3][3] = -6.7;
}

void fill_in_complements_check(matrix_t *A) {
  A->matrix[0][0] = -32.64;
  A->matrix[0][1] = 32.64;
  A->matrix[0][2] = 32.64;
  A->matrix[0][3] = -32.64;
  A->matrix[1][0] = 32.64;
  A->matrix[1][1] = 147.774;
  A->matrix[1][2] = -164.148;
  A->matrix[1][3] = -72.426;
  A->matrix[2][0] = 32.64;
  A->matrix[2][1] = 227.1;
  A->matrix[2][2] = -56.04;
  A->matrix[2][3] = -91.38;
  A->matrix[3][0] = -32.64;
  A->matrix[3][1] = -168.834;
  A->matrix[3][2] = 28.428;
  A->matrix[3][3] = 116.886;
}

void fill_inverse_check(matrix_t *A) {
  A->matrix[0][0] = 0.0854700854700855;
  A->matrix[0][1] = -0.0854700854700855;
  A->matrix[0][2] = -0.0854700854700855;
  A->matrix[0][3] = 0.0854700854700855;
  A->matrix[1][0] = -0.0854700854700855;
  A->matrix[1][1] = -0.38695638511815;
  A->matrix[1][2] = -0.594676973353444;
  A->matrix[1][3] = 0.442103443941679;
  A->matrix[2][0] = -0.0854700854700855;
  A->matrix[2][1] = 0.429832830568125;
  A->matrix[2][2] = 0.146744595274007;
  A->matrix[2][3] = -0.0744406737053796;
  A->matrix[3][0] = 0.0854700854700855;
  A->matrix[3][1] = 0.189652463549522;
  A->matrix[3][2] = 0.239284816490699;
  A->matrix[3][3] = -0.306074032176973;
}

START_TEST(s21_eq_matrix_test_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  int check = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(check, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  fill_in_matrix(&A);
  fill_in_matrix(&B);
  int check = 1;
  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  fill_in_matrix(&A);
  A.matrix[3][2] = -15;
  fill_in_matrix(&B);
  int check = 0;
  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 2, &B);
  fill_in_matrix(&A);
  fill_in_matrix(&B);
  int check = 0;
  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  fill_in_matrix(&A);
  fill_in_matrix(&B);
  int check = 1;
  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_sum_matrix_test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  fill_in_matrix(&B);
  fill_in_sum_mul_check(&R_check);
  s21_sum_matrix(&A, &B, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_sub_matrix_test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  fill_in_matrix(&B);
  for (int i = 0; i < R_check.rows; i++) {
    for (int j = 0; j < R_check.columns; j++) {
      R_check.matrix[i][j] = 0;
    }
  }
  s21_sub_matrix(&A, &B, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_mult_number_test_1) {
  matrix_t A;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 4, &A);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  fill_in_sum_mul_check(&R_check);
  s21_mult_number(&A, 2, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t A;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 4, &A);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  fill_in_matrix(&R_check);
  s21_mult_number(&A, 1, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_mult_matrix_test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 4, &B);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  fill_in_matrix(&B);
  fill_in_mat_mul_check(&R_check);
  s21_mult_matrix(&A, &B, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t A;
  matrix_t B;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(4, 4, &B);
  // s21_create_matrix(2, 2, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  fill_in_matrix(&B);
  fill_in_mat_mul_check(&R_check);
  int result = s21_mult_matrix(&A, &B, &R);
  int check = 2;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_transpose_test_1) {
  matrix_t A;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 4, &A);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  fill_in_transpose_check(&R_check);
  s21_transpose(&A, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t A;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(1, 1, &A);
  // s21_create_matrix(1, 1, &R);
  s21_create_matrix(1, 1, &R_check);
  fill_in_matrix(&A);
  R_check.matrix[0][0] = -1.7;
  s21_transpose(&A, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t A;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(3, 4, &A);
  // s21_create_matrix(4, 3, &R);
  s21_create_matrix(4, 3, &R_check);
  fill_in_matrix(&A);
  R_check.matrix[0][0] = -1.7;
  R_check.matrix[0][1] = 2.7;
  R_check.matrix[0][2] = 0.3;
  R_check.matrix[1][0] = -0.5;
  R_check.matrix[1][1] = 0.9;
  R_check.matrix[1][2] = -4.5;
  R_check.matrix[2][0] = 0.7;
  R_check.matrix[2][1] = 3.1;
  R_check.matrix[2][2] = -1.3;
  R_check.matrix[3][0] = 1.9;
  R_check.matrix[3][1] = 1.3;
  R_check.matrix[3][2] = -6.1;
  s21_transpose(&A, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_calc_complements_test_1) {
  matrix_t A;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 4, &A);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  A.matrix[0][0] = 10;
  fill_in_complements_check(&R_check);
  s21_calc_complements(&A, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_determinant_test_1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  fill_in_matrix(&A);
  double result = -1.0;
  s21_determinant(&A, &result);
  double check = -1.7;
  s21_remove_matrix(&A);
  ck_assert_float_eq_tol(check, result, 0.00000001);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  fill_in_matrix(&A);
  A.matrix[0][0] = 10;
  double result = -1.0;
  s21_determinant(&A, &result);
  double check = -381.888;
  s21_remove_matrix(&A);
  ck_assert_float_eq_tol(check, result, 0.00000001);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A;
  s21_create_matrix(4, 3, &A);
  fill_in_matrix(&A);
  A.matrix[0][0] = 10;
  double result = -1.0;
  int res = s21_determinant(&A, &result);
  int check = 2;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, res);
}
END_TEST

START_TEST(s21_s21_inverse_matrix_test_1) {
  matrix_t A;
  matrix_t R;
  matrix_t R_check;
  s21_create_matrix(4, 4, &A);
  // s21_create_matrix(4, 4, &R);
  s21_create_matrix(4, 4, &R_check);
  fill_in_matrix(&A);
  A.matrix[0][0] = 10;
  fill_inverse_check(&R_check);
  s21_inverse_matrix(&A, &R);
  int check = 1;
  int result = s21_eq_matrix(&R_check, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R_check);
  ck_assert_int_eq(check, result);
}
END_TEST

START_TEST(s21_s21_inverse_matrix_test_2) {
  matrix_t A;
  matrix_t R;
  s21_create_matrix(4, 4, &A);
  // s21_create_matrix(4, 4, &R);
  fill_in_matrix(&A);
  int result = s21_inverse_matrix(&A, &R);
  int check = 2;
  s21_remove_matrix(&A);
  // s21_remove_matrix(&R);
  ck_assert_int_eq(check, result);
}
END_TEST

void srunner_add_matrix_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Matrix");
  TCase *tc1_1 = tcase_create("Matrix");
  suite_add_tcase(save_v1, tc1_1);
  tcase_add_test(tc1_1, s21_eq_matrix_test_1);
  tcase_add_test(tc1_1, s21_eq_matrix_test_2);
  tcase_add_test(tc1_1, s21_eq_matrix_test_3);
  tcase_add_test(tc1_1, s21_eq_matrix_test_4);
  tcase_add_test(tc1_1, s21_eq_matrix_test_5);
  tcase_add_test(tc1_1, s21_sum_matrix_test_1);
  tcase_add_test(tc1_1, s21_sub_matrix_test_1);
  tcase_add_test(tc1_1, s21_mult_number_test_1);
  tcase_add_test(tc1_1, s21_mult_number_test_2);
  tcase_add_test(tc1_1, s21_mult_matrix_test_1);
  tcase_add_test(tc1_1, s21_mult_matrix_test_2);
  tcase_add_test(tc1_1, s21_transpose_test_1);
  tcase_add_test(tc1_1, s21_transpose_test_2);
  tcase_add_test(tc1_1, s21_transpose_test_3);
  tcase_add_test(tc1_1, s21_calc_complements_test_1);
  tcase_add_test(tc1_1, s21_determinant_test_1);
  tcase_add_test(tc1_1, s21_determinant_test_2);
  tcase_add_test(tc1_1, s21_determinant_test_3);
  tcase_add_test(tc1_1, s21_s21_inverse_matrix_test_1);
  tcase_add_test(tc1_1, s21_s21_inverse_matrix_test_2);
  srunner_add_suite(sr, save_v1);
}

int main(void) {
  Suite *s = suite_create("Matrix tests");
  SRunner *sr = srunner_create(s);
  int nf;

  srunner_add_matrix_tests(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}