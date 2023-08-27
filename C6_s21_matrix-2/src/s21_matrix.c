#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows <= 0 || columns <= 0 || !result) {
    error = 1;
  } else {
    result->columns = columns;
    result->rows = rows;
    result->matrix = calloc(rows, sizeof(double *));
    *(result->matrix) = calloc(rows * columns, sizeof(double));
    for (int i = 0; i < rows; i++) {
      *(result->matrix + i) = *result->matrix + i * columns;
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (is_correct_matrix(A)) {
    free(*(A->matrix));
    free(A->matrix);
    // free(A);
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->matrix == NULL || B->matrix == NULL || A->columns != B->columns ||
      A->rows != B->rows) {
    res = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.00000005) {
          res = FAILURE;
        }
      }
    }
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  error = matrix_arithmetics(A, B, result, sum);
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  error = matrix_arithmetics(A, B, result, sub);
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if (!is_correct_matrix(A)) {
    error = 1;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (!is_correct_matrix(A) || !is_correct_matrix(B)) {
    error = 1;
  } else if (A->columns != B->rows) {
    error = 2;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (!is_correct_matrix(A)) {
    error = 1;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (!is_correct_matrix(A)) {
    error = 1;
  } else if (A->columns != A->rows || A->columns < 2) {
    error = 2;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        double minor_det = 0;
        matrix_t M;
        s21_create_matrix(A->columns - 1, A->rows - 1, &M);
        fill_minor(A, i, j, &M);
        s21_determinant(&M, &minor_det);
        result->matrix[i][j] = minor_det * pow(-1, i + j);
        s21_remove_matrix(&M);
      }
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (!is_correct_matrix(A)) {
    error = 1;
  } else if (A->columns != A->rows || A->columns < 1) {
    error = 2;
  } else {
    if (A->columns == 1 || A->columns == 2) {
      *result = small_matrix_determinant(A);
    } else {
      *result = big_matrix_determinant(A);
    }
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (!is_correct_matrix(A)) {
    error = 1;
  } else if (A->columns != A->rows || A->columns < 2) {
    error = 2;
  } else {
    double det = 0;
    s21_determinant(A, &det);
    if (fabs(det) < 0.0000000001) {
      error = 2;
    } else {
      matrix_t C;
      matrix_t CT;
      det = 1 / det;
      s21_calc_complements(A, &C);
      s21_transpose(&C, &CT);
      // printf("1\n");
      s21_mult_number(&CT, det, result);
      // printf("2\n");
      s21_remove_matrix(&C);
      s21_remove_matrix(&CT);
    }
  }
  return error;
}

int matrix_arithmetics(matrix_t *A, matrix_t *B, matrix_t *result,
                       double (*func)(double, double)) {
  int error = 0;
  if (!is_correct_matrix(A) || !is_correct_matrix(B)) {
    error = 1;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    error = 2;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = func(A->matrix[i][j], B->matrix[i][j]);
      }
    }
  }
  return error;
}

double sum(double a, double b) { return a + b; }

double sub(double a, double b) { return a - b; }

// int print_matrix(matrix_t *A) {
//   int error = 0;
//   if (!is_correct_matrix(A)) {
//     error = 1;
//   } else {
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         printf("%10.3lf ", A->matrix[i][j]);
//       }
//       printf("\n");
//     }
//   }
//   return error;
// }

// int copy_matrix(matrix_t *dst, matrix_t *src) {
//   int error = 0;
//   if (!is_correct_matrix(src)) {
//     error = 1;
//   } else {
//     // s21_remove_matrix(dst);
//     // s21_create_matrix(src->rows, src->columns, dst);
//     for (int i = 0; i < src->rows; i++) {
//       for (int j = 0; j < src->columns; j++) {
//         dst->matrix[i][j] = src->matrix[i][j];
//       }
//     }
//   }
//   return error;
// }

int is_correct_matrix(matrix_t *A) {
  int corret = 0;
  if (A != NULL && A->columns > 0 && A->rows > 0) {
    corret = 1;
  }
  return corret;
}

double small_matrix_determinant(matrix_t *A) {
  double result = 0;
  if (A->columns == 1) {
    result = A->matrix[0][0];
  } else if (A->columns == 2) {
    result =
        (A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0]);
  }
  return result;
}

double big_matrix_determinant(matrix_t *A) {
  double result = 0;
  for (int i = 0; i < A->columns; i++) {
    double minor_det = 0;
    matrix_t M;
    s21_create_matrix(A->columns - 1, A->rows - 1, &M);
    fill_minor(A, 0, i, &M);
    s21_determinant(&M, &minor_det);
    result += A->matrix[0][i] * minor_det * pow(-1, i);
    s21_remove_matrix(&M);
  }
  return result;
}

void fill_minor(matrix_t *A, int row, int column, matrix_t *M) {
  int m = 0;
  for (int i = 0; i < A->rows; i++) {
    int n = 0;
    if (i != row) {
      for (int j = 0; j < A->rows; j++) {
        if (j != column) {
          M->matrix[m][n] = A->matrix[i][j];
          n++;
        }
      }
      m++;
    }
  }
}