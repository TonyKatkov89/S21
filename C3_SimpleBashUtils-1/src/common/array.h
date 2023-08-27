#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array {
  char** elements;
  int array_size;
} array_s;

array_s* array_init();
void add_to_array(char* element, array_s* array);
char* get_long_string(FILE* file, char* c);
int file_to_array(char* filename, array_s* array);

#endif