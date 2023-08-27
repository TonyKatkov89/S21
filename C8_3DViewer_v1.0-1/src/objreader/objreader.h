#ifndef OBJREADER_H
#define OBJREADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct coords {
  double x;
  double y;
  double z;
} coords_t;

int fileRead(const char *fileName, coords_t **arrayOfCoords,
             int ***arrayOfFaces, int **fElementsCount, int *vCount_,
             int *fCount_);
int parseVLine(char *stringLine, coords_t ***arrayOfCoords, int vCount);
int parseFLine(char *stringLine, int **arrayItemOfArrayOfFaces,
               int ***fElementsCount, int fCount);

#endif
