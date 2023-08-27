#include "grep_parcer.h"

flags_s* flags_init() {
  flags_s* tmp = (flags_s*)malloc(sizeof(flags_s));
  tmp->e = 0;
  tmp->i = 0;
  tmp->v = 0;
  tmp->c = 0;
  tmp->l = 0;
  tmp->n = 0;
  tmp->h = 0;
  tmp->s = 0;
  tmp->f = 0;
  tmp->o = 0;
  return tmp;
}

int parce_flags(char* arg, flags_s* flags) {
  int error = 0;
  if (*arg == '-') {
    if (trigger_flags(arg, flags)) {
      error = 1;
    }
  }

  return error;
}

int parce_files_and_patterns(char* arg, flags_s* flags, array_s* patterns,
                             array_s* files, char* last_flag) {
  int error = 0;
  if (*last_flag == 'e') {
    add_to_array(arg, patterns);
    *last_flag = '0';
  } else if (*last_flag == 'f') {
    error = file_to_array(arg, patterns);
    *last_flag = '0';
  } else if (*arg == '-') {
    while (*(arg) && *arg != 'e' && *arg != 'f') {
      arg++;
    }
    if (*arg == 'e') {
      arg++;
      if (*arg != 0) {
        add_to_array(arg, patterns);
      } else {
        *last_flag = 'e';
      }
    } else if (*arg == 'f') {
      arg++;
      if (*arg != 0) {
        error = file_to_array(arg, patterns);
      } else {
        *last_flag = 'f';
      }
    }
  } else if (flags->e == 0 && flags->f == 0 && patterns->array_size == 0) {
    add_to_array(arg, patterns);
  } else {
    add_to_array(arg, files);
  }

  return error;
}

char trigger_flags(char* arg, flags_s* flags) {
  char error = 0;
  int stop_parcing = 0;
  fflush(stdout);
  arg++;
  while (*arg && !stop_parcing) {
    fflush(stdout);
    if (*arg == 'e') {
      flags->e = 1;
      stop_parcing = 1;
    } else if (*arg == 'i') {
      flags->i = 1;
    } else if (*arg == 'v') {
      flags->v = 1;
    } else if (*arg == 'c') {
      flags->c = 1;
    } else if (*arg == 'l') {
      flags->l = 1;
    } else if (*arg == 'n') {
      flags->n = 1;
    } else if (*arg == 'h') {
      flags->h = 1;
    } else if (*arg == 's') {
      flags->s = 1;
    } else if (*arg == 'f') {
      flags->f = 1;
    } else if (*arg == 'o') {
      flags->o = 1;
    } else if (*arg != 0) {
      error = *arg;
      stop_parcing = 1;
    }
    arg++;
  }

  return error;
}

void remove_duplicating_patterns(array_s* patterns) {
  for (int i = 0; i < patterns->array_size; i++) {
    for (int j = i + 1; j < patterns->array_size; j++) {
      if (!strcmp(patterns->elements[i], patterns->elements[j])) {
        for (int k = j; k < patterns->array_size - 1; k++) {
          patterns->elements[k] = patterns->elements[k + 1];
          patterns->elements[k] = patterns->elements[k + 1];
        }
        patterns->array_size--;
        free(patterns->elements[patterns->array_size]);
      }
    }
  }
}