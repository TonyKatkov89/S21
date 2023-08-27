#include "transform.h"

coords_t *FitToWindow(coords_t *arrayOfCoords, int vCount) {
  coords_t *centeredCoords = calloc(vCount, sizeof(coords_t));
  double x0 = 0;
  double y0 = 0;
  double z0 = 0;
  double scale = FindScale(arrayOfCoords, vCount, &x0, &y0, &z0);
  for (int i = 0; i < vCount; i++) {
    centeredCoords[i].x = (arrayOfCoords[i].x - x0) / scale;
    centeredCoords[i].y = (arrayOfCoords[i].y - y0) / scale;
    centeredCoords[i].z = (arrayOfCoords[i].z - z0) / scale;
  }
  return centeredCoords;
}

coords_t *Move(coords_t *arrayOfCoords, int vCount, double moveX, double moveY,
               double moveZ) {
  coords_t *movedCoords = calloc(vCount, sizeof(coords_t));
  for (int i = 0; i < vCount; i++) {
    movedCoords[i].x = arrayOfCoords[i].x + moveX;
    movedCoords[i].y = arrayOfCoords[i].y + moveY;
    movedCoords[i].z = arrayOfCoords[i].z + moveZ;
  }
  return movedCoords;
}

coords_t *Resize(coords_t *arrayOfCoords, int vCount, double ratio) {
  coords_t *resizedCoords = calloc(vCount, sizeof(coords_t));
  for (int i = 0; i < vCount; i++) {
    resizedCoords[i].x = arrayOfCoords[i].x * ratio;
    resizedCoords[i].y = arrayOfCoords[i].y * ratio;
    resizedCoords[i].z = arrayOfCoords[i].z * ratio;
  }
  return resizedCoords;
}

coords_t *Rotate(coords_t *arrayOfCoords, int vCount, double rotateX,
                 double rotateY, double rotateZ) {
  double x0 = 1, y0 = 1, z0 = 1;
  coords_t *rotatedCoords = calloc(vCount, sizeof(coords_t));
  matrix_t rotateMatrix;
  FindScale(arrayOfCoords, vCount, &x0, &y0, &z0);
  s21_create_matrix(3, 3, &rotateMatrix);
  FillRotateMatrix(&rotateMatrix, rotateX, rotateY, rotateZ);
  for (int i = 0; i < vCount; i++) {
    matrix_t vector;
    matrix_t rotatedVector;
    s21_create_matrix(3, 1, &vector);
    vector.matrix[0][0] = arrayOfCoords[i].x - x0;
    vector.matrix[1][0] = arrayOfCoords[i].y - y0;
    vector.matrix[2][0] = arrayOfCoords[i].z - z0;
    s21_mult_matrix(&rotateMatrix, &vector, &rotatedVector);
    rotatedCoords[i].x = rotatedVector.matrix[0][0] + x0;
    rotatedCoords[i].y = rotatedVector.matrix[1][0] + y0;
    rotatedCoords[i].z = rotatedVector.matrix[2][0] + z0;
    s21_remove_matrix(&vector);
    s21_remove_matrix(&rotatedVector);
  }
  // for (int i = 0; i < vCount; i++) {
  //           printf("v[%d]: %.4f, %.4f, %.4f\n", i, rotatedCoords[i].x,
  //           rotatedCoords[i].y, rotatedCoords[i].z);
  // }
  s21_remove_matrix(&rotateMatrix);
  return rotatedCoords;
}

// coords_t *Rotate(coords_t *arrayOfCoords, int vCount, double rotateX,
//                  double rotateY, double rotateZ) {
//   double x0, y0, z0;
//   coords_t *rotatedCoords = calloc(vCount, sizeof(coords_t));
//   matrix_t rotateMatrix;
//   FindScale(arrayOfCoords, vCount, &x0, &y0, &z0);
//   s21_create_matrix(3, 3, &rotateMatrix);
//   FillRotateMatrix(&rotateMatrix, rotateX, rotateY, rotateZ);
//   for (int i = 0; i < vCount; i++) {
//     matrix_t vector;
//     matrix_t rotatedVector;
//     s21_create_matrix(3, 1, &vector);
//     vector.matrix[0][0] = arrayOfCoords[i].x - x0;
//     vector.matrix[1][0] = arrayOfCoords[i].y - y0;
//     vector.matrix[2][0] = arrayOfCoords[i].z - z0;
//     s21_mult_matrix(&rotateMatrix, &vector, &rotatedVector);
//     rotatedCoords[i].x = rotatedVector.matrix[0][0] + x0;
//     rotatedCoords[i].y = rotatedVector.matrix[1][0] + y0;
//     rotatedCoords[i].z = rotatedVector.matrix[2][0] + z0;
//     s21_remove_matrix(&vector);
//     s21_remove_matrix(&rotatedVector);
//   }
//   s21_remove_matrix(&rotateMatrix);
//   return rotatedCoords;
// }

double FindScale(coords_t *arrayOfCoords, int vCount, double *x0, double *y0,
                 double *z0) {
  double scale = 1;
  if (arrayOfCoords != NULL) {
    double maxX, minX, maxY, minY, maxZ, minZ;
    maxX = minX = arrayOfCoords[0].x;
    maxY = minY = arrayOfCoords[0].y;
    maxZ = minZ = arrayOfCoords[0].z;

    for (int i = 1; i < vCount; i++) {
      if (arrayOfCoords[i].x > maxX) maxX = arrayOfCoords[i].x;
      if (arrayOfCoords[i].x < minX) minX = arrayOfCoords[i].x;
      if (arrayOfCoords[i].y > maxY) maxY = arrayOfCoords[i].y;
      if (arrayOfCoords[i].y < minY) minY = arrayOfCoords[i].y;
      if (arrayOfCoords[i].z > maxZ) maxZ = arrayOfCoords[i].z;
      if (arrayOfCoords[i].z < minZ) minZ = arrayOfCoords[i].z;
    }

    *x0 = (maxX + minX) / 2;
    *y0 = (maxY + minY) / 2;
    *z0 = (maxZ + minZ) / 2;

    if (maxX - minX >= maxY - minY) {
      scale = maxX - minX;
    } else {
      scale = maxY - minY;
    }
    if (maxZ - minZ > scale) {
      scale = maxZ - minZ;
    }
  }
  return scale / 2;
}

void FillRotateMatrix(matrix_t *A, double rotateX, double rotateY,
                      double rotateZ) {
  double a = cos(rotateX);
  double b = sin(rotateX);
  double c = cos(rotateY);
  double d = sin(rotateY);
  double e = cos(rotateZ);
  double f = sin(rotateZ);
  A->matrix[0][0] = c * e;
  A->matrix[0][1] = -c * f;
  A->matrix[0][2] = -d;
  A->matrix[1][0] = -b * d * e + a * f;
  A->matrix[1][1] = b * d * f + a * e;
  A->matrix[1][2] = -b * c;
  A->matrix[2][0] = a * d * e + b * f;
  A->matrix[2][1] = -a * d * f + b * e;
  A->matrix[2][2] = a * c;
}
