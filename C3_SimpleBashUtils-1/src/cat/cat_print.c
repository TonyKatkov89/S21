#include "cat_print.h"

void print_files(array_s* files_to_print, flags_s* flags) {
  char c1 = 0, c2 = '\n', c3 = 0;
  int line_num = 0;
  for (int i = 0; i < files_to_print->array_size; i++) {
    FILE* file = fopen(files_to_print->elements[i], "r");
    if (file == NULL) {
      printf("s21_cat: %s: No such file or directory\n",
             files_to_print->elements[i]);
    } else {
      while ((c1 = fgetc(file)) != EOF) {
        if (!(c1 == 10 && c2 == 10 && c3 == 10 && flags->s != 0)) {
          if (c2 == 10 && flags->n != 0) {
            print_line_number(c1, flags, &line_num);
          }
          if (is_char_non_printable(c1)) {
            print_non_printable(c1, flags);
          } else {
            printf("%c", c1);
          }
        }
        c3 = c2;
        c2 = c1;
      }
      fclose(file);
    }
  }
}

void print_line_number(char c1, flags_s* flags, int* line_num) {
  if (c1 != 10 || flags->b == 0) {
    (*line_num)++;
    printf("%6d%c", *line_num, 9);
  }
}

void print_non_printable(char non_printable_char, flags_s* flags) {
  if (non_printable_char == 10) {
    if (flags->e != 0) {
      printf("$%c", non_printable_char);
    } else {
      printf("%c", non_printable_char);
    }
  } else if (non_printable_char == 9) {
    if (flags->t != 0) {
      printf("^I");
    } else {
      printf("%c", non_printable_char);
    }
  } else if (flags->v != 0) {
    if (non_printable_char == 0) {
      printf("^@");
    } else if (non_printable_char == 27) {
      printf("^[");
    } else if (non_printable_char == 28) {
      printf("^\\");
    } else if (non_printable_char == 29) {
      printf("^]");
    } else if (non_printable_char == 30) {
      printf("^^");
    } else if (non_printable_char == 31) {
      printf("^_");
    } else if (non_printable_char == 127) {
      printf("^?");
    } else if ((non_printable_char > 0 && non_printable_char < 9) ||
               (non_printable_char > 10 && non_printable_char < 33)) {
      printf("^%c", non_printable_char + 64);
    }
  } else {
    printf("%c", non_printable_char);
  }
}

int is_char_non_printable(char c) {
  int non_printable = 0;
  if (c < 32 || c == 127) {
    non_printable = 1;
  }
  return non_printable;
}
