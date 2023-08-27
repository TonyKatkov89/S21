#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <math.h>

#include "../matrix/s21_matrix.h"
#include "objreader.h"

coords_t *FitToWindow(coords_t *arrayOfCoords, int vCount);
coords_t *Move(coords_t *arrayOfCoords, int vCount, double moveX, double moveY,
               double moveZ);
coords_t *Resize(coords_t *arrayOfCoords, int vCount, double ratio);
coords_t *Rotate(coords_t *arrayOfCoords, int vCount, double rotateX,
                 double rotateY, double rotateZ);
double FindScale(coords_t *arrayOfCoords, int vCount, double *x0, double *y0,
                 double *z0);
void FillRotateMatrix(matrix_t *A, double rotateX, double rotateY,
                      double rotateZ);

#endif
