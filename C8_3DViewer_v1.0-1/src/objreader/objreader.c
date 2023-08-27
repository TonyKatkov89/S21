#include "objreader.h"

int fileRead(const char *fileName, coords_t **arrayOfCoords,
             int ***arrayOfFaces, int **fElementsCount, int *vCount_,
             int *fCount_) {
  FILE *ptr;
  int res = 0, vCount = 0, fCount = 0;
  // res = 0 - ok, 1 - fail

  ptr = fopen(fileName, "r");
  //  int *fElementsCount = (int*) malloc(1 * sizeof(int));

  if (NULL == ptr) {
    printf("file can't be opened \n");
    res = 1;
  } else {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, ptr)) != -1) {
      // printf("Retrieved line of length %zu :\n", read);

      if (read > 1 && *line == 'v' && line[1] == ' ') {
        //   printf("%s", line);
        vCount++;
        *arrayOfCoords = realloc(*arrayOfCoords, sizeof(coords_t) * vCount);
        parseVLine(line, &arrayOfCoords, vCount);
      } else if (read > 1 && *line == 'f' && line[1] == ' ') {
        //  printf("%s", line);
        fCount++;
        *arrayOfFaces = realloc(*arrayOfFaces, sizeof(int *) * fCount);
        (*arrayOfFaces)[fCount - 1] = (int *)malloc(sizeof(int) * 1);
        parseFLine(line, &(*arrayOfFaces)[fCount - 1], &fElementsCount, fCount);
      }
    }

    if (line) free(line);
    fclose(ptr);
  }

  *vCount_ = vCount;
  *fCount_ = fCount;
  // free(fElementsCount);

  return res;
}

int parseVLine(char *stringLine, coords_t ***arrayOfCoords, int vCount) {
  char *lineX = "", *lineY = "", *lineZ = "";
  double x, y, z;
  char *ptr;
  char *token = strtok(stringLine, " ");
  int i = 0;
  while (token != NULL) {
    //   printf( "token %s\n", token );

    if (i == 1) {
      lineX = token;
    } else if (i == 2) {
      lineY = token;
    } else if (i == 3) {
      lineZ = token;
    }

    token = strtok(NULL, " ");
    i++;
  }

  //  printf("i = %d", i);

  //  printf( "lineX %s\n", lineX );
  //  printf( "lineY %s\n", lineY );
  //  printf( "lineZ %s\n", lineZ );

  x = strtod(lineX, &ptr);
  y = strtod(lineY, &ptr);
  z = strtod(lineZ, &ptr);

  (**arrayOfCoords)[vCount - 1].x = x;
  (**arrayOfCoords)[vCount - 1].y = y;
  (**arrayOfCoords)[vCount - 1].z = z;

  // printf("\n\nx is %f\n\n", (**arrayOfCoords)[vCount-1].x);
  // printf("\n\ny is %f\n\n", (**arrayOfCoords)[vCount-1].y);
  // printf("\n\nz is %f\n\n", (**arrayOfCoords)[vCount-1].z);

  return 0;
}

int parseFLine(char *stringLine, int **arrayItemOfArrayOfFaces,
               int ***fElementsCount, int fCount) {
  int b = 1;
  //  int *out = (int*) malloc(b * sizeof(int));
  char *token = strtok(stringLine, " ");
  while (token != NULL) {
    int tmp = atoi(token);
    if (tmp != 0) {
      (*arrayItemOfArrayOfFaces)[b - 1] = tmp;
      b++;
      *arrayItemOfArrayOfFaces =
          realloc(*arrayItemOfArrayOfFaces, (b * sizeof(int)));

      // printf("\n__%d__\n", tmp);
    }
    token = strtok(NULL, " ");
  }

  **fElementsCount = realloc(**fElementsCount, (fCount * sizeof(int)));
  (**fElementsCount)[fCount - 1] = b;

  //  printf("\nb = %d\n", b);

  //   for (int i = 0; i < b - 2; i++) {
  //     printf("\n..%d..\n", *out_[i]);
  // }
  //  *out_ = (int*) malloc(b * sizeof(int));

  //   out_ = &out;

  //  free(out);

  return 0;
}
