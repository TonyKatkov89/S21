#include "grep_print.h"

void print(array_s* patterns, array_s* files, flags_s* flags) {
  for (int i = 0; i < files->array_size; i++) {
    matching_line_s** matching_lines = calloc(1, sizeof(matching_line_s*));
    int lines_qtty = 0;
    FILE* file = fopen(files->elements[i], "r");
    if (file == NULL) {
      if (flags->s == 0) {
        //fprintf(stderr, "s21_grep: %s: No such file or directory\n", files->elements[i]);
        //fflush(stderr);
        print_no_file_error(files->elements[i]);
        free(matching_lines);
      }
    } else {
      char c = fgetc(file);
      int line_num = -1;
      while (c != EOF) {
        char* s = get_long_string(file, &c);
        line_num++;
        int line_added = 0;
        for (int j = 0; j < patterns->array_size; j++) {
          int regc;
          regex_t preg;
          size_t nmatch = 100;
          regmatch_t pmatch[100];
          if (flags->i == 1) {
            regc = regcomp(&preg, patterns->elements[j], REG_ICASE);
          } else {
            regc = regcomp(&preg, patterns->elements[j], 0);
          }
          if (!regc) {
            if (!regexec(&preg, s, nmatch, pmatch, 0)) {
              if (!line_added) {
                matching_lines =
                    add_line(matching_lines, &lines_qtty, line_num);
                line_added = 1;
              }
              add_match(matching_lines[lines_qtty - 1], pmatch[0].rm_so,
                        pmatch[0].rm_eo);
              find_next_match(preg, &s[pmatch[0].rm_eo], matching_lines,
                              lines_qtty, pmatch[0].rm_eo);
            }
          }
          regfree(&preg);
        }
        free(s);
        if (lines_qtty > 0) {
          clean_matches(matching_lines[lines_qtty - 1]);
        }
      }
      if (flags->l == 1 && lines_qtty) {
        printf("\033[1;35m%s\033[0m\n", files->elements[i]);
      } else if (flags->c == 1) {
        if (flags->h == 0) {
          printf("\033[1;35m%s\033[1;36m%c\033[0m", files->elements[i], ':');
        }
        printf("%d\n", lines_qtty);
      } else {
        print_file(matching_lines, file, files->elements[i], lines_qtty, flags);
      }
      fclose(file);
      if (lines_qtty) {
        free_matching_lines(matching_lines, lines_qtty);
      } else {
        free(matching_lines);
      }
    }
  }
}

void print_file(matching_line_s** matching_lines, FILE* file, char* filename,
                int lines_qtty, flags_s* flags) {
  rewind(file);
  char c = fgetc(file);
  int line_num = -1;
  while (c != EOF) {
    char* s = get_long_string(file, &c);
    line_num++;
    if (flags->v != 0 && flags->o == 0) {
      int has_matches = 0;
      for (int i = 0; i < lines_qtty; i++) {
        if (matching_lines[i]->line_number == line_num) {
          has_matches = 1;
        }
      }
      if (has_matches == 0) {
        print_file_and_line(filename, line_num, flags, 0);
        printf("%s\n", s);
      }
    } else if (flags->v == 0) {
      for (int i = 0; i < lines_qtty; i++) {
        if (matching_lines[i]->line_number == line_num) {
          print_file_and_line(filename, line_num, flags, 0);
          print_line(matching_lines[i], s, flags, filename);
        }
      }
    }
    free(s);
  }
}

void print_line(matching_line_s* matching_line, char* s, flags_s* flags,
                char* filename) {
  for (int i = 0; i < matching_line->matches_number; i++) {
    if (i == 0 && flags->o == 0) {
      printf("%.*s", matching_line->so[i], s);
    }
    print_file_and_line(filename, matching_line->line_number, flags, 1);
    printf("\033[1;31m%.*s\033[0m", matching_line->eo[i] - matching_line->so[i],
           &s[matching_line->so[i]]);
    if (i < matching_line->matches_number - 1 && flags->o == 0) {
      printf("%.*s", matching_line->so[i + 1] - matching_line->eo[i],
             &s[matching_line->eo[i]]);
    } else if (flags->o == 0) {
      printf("%s\n", &s[matching_line->eo[i]]);
    }
    if (flags->o != 0) {
      printf("\n");
    }
  }
}

void print_file_and_line(char* filename, int line_number, flags_s* flags,
                         int needed_flag) {
  if (flags->h == 0 && flags->o == needed_flag) {
    printf("\033[1;35m%s\033[1;36m%c\033[0m", filename, ':');
  }
  if (flags->n != 0 && flags->o == needed_flag) {
    printf("\033[1;32m%d\033[1;36m%c\033[0m", line_number + 1, ':');
  }
}

void print_no_file_error(char* filename) {
  char* str = calloc(strlen(filename) + 50, sizeof(char));
  strcat(str, "s21_grep: ");
  strcat(str, filename); 
  //strcat(str, ": No such file or directory\n");
  perror(str);
  free(str);
}