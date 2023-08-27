#include "cat_parcer.h"

flags_s* initializing() {
  flags_s* tmp = (flags_s*)malloc(sizeof(flags_s));
  tmp->b = 0;
  tmp->e = 0;
  tmp->n = 0;
  tmp->s = 0;
  tmp->t = 0;
  tmp->v = 0;
  return tmp;
}

int parce_argument(char* arg, flags_s* flags, array_s* files_to_print) {
  int error = 0;
  char error_char = 0;
  if (*arg == '-') {
    error_char = trigger_flags(arg, flags);
  } else {
    add_to_array(arg, files_to_print);
  }

  if (error_char != 0) {
    error = 1;
    printf("s21_cat: invalid option -- '%c'\n", error_char);
    printf(
        "Try 's21_cat --help' for more information. Wait.. there is no --help. "
        "Sorry :(\n");
  }

  return error;
}

char trigger_flags(char* arg, flags_s* flags) {
  char error = 0;
  arg++;
  if (strcmp(arg, "-number-nonblank") == 0) {
    flags->b = 1;
    flags->n = 1;
  } else if (strcmp(arg, "-number") == 0) {
    flags->n = 1;
  } else if (strcmp(arg, "-squeeze-blank") == 0) {
    flags->s = 1;
  } else {
    while (*arg && !error) {
      if (*arg == 'b') {
        flags->b = 1;
        flags->n = 1;
      } else if (*arg == 'n') {
        flags->n = 1;
      } else if (*arg == 's') {
        flags->s = 1;
      } else if (*arg == 'v') {
        flags->v = 1;
      } else if (*arg == 'E') {
        flags->e = 1;
      } else if (*arg == 'e') {
        flags->e = 1;
        flags->v = 1;
      } else if (*arg == 't') {
        flags->t = 1;
        flags->v = 1;
      } else if (*arg == 'T') {
        flags->t = 1;
      } else if (*arg != 0) {
        error = *arg;
      }
      arg++;
    }
  }

  return error;
}