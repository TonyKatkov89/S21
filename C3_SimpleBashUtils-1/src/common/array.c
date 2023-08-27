#include "array.h"

array_s* array_init() {
  array_s* tmp = (array_s*)malloc(sizeof(array_s));
  tmp->elements = calloc(1, sizeof(char*));
  tmp->array_size = 0;
  return tmp;
}

void add_to_array(char* element, array_s* array) {
  int element_length = 8;
  array->array_size++;
  array->elements =
      realloc(array->elements, (array->array_size) * sizeof(char*));
  *(array->elements + array->array_size - 1) =
      calloc(element_length, sizeof(char));
  *(*(array->elements + array->array_size - 1)) = *element;
  for (int i = 1; *element; i++) {
    if (i >= element_length) {
      element_length *= 2;
      *(array->elements + array->array_size - 1) =
          realloc(*(array->elements + array->array_size - 1),
                  element_length * sizeof(char));
    }
    element++;
    *(*(array->elements + array->array_size - 1) + i) = *element;
  }
}

char* get_long_string(FILE* file, char* c) {
  int str_len = 8;
  char* s = calloc(str_len, sizeof(char));
  int i = 0;
  for (; *c != '\n' && *c != EOF; i++) {
    if (i >= str_len - 2) {
      str_len *= 2;
      s = realloc(s, str_len * sizeof(char));
      for (int j = i; j < str_len; j++) {
        s[j] = 0;
      }
    }
    s[i] = *c;
    *c = fgetc(file);
  }
  s[i + 1] = 0;
  if (*c == '\n') {
    *c = fgetc(file);
  }

  return s;
}

int file_to_array(char* filename, array_s* array) {
  int error = 0;
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("s21_grep: %s: No such file or directory\n", filename);
    error = 1;
  } else {
    char c = fgetc(file);
    while (c != EOF) {
      char* s = get_long_string(file, &c);
      add_to_array(s, array);
      free(s);
    }
    fclose(file);
  }

  return error;
}