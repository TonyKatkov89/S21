#include "grep_print.h"

void print(array_s* patterns, array_s* files, flags_s* flags) {
  start_color();
  init_pair(1, 1, 0);
  init_pair(9, 7, 0);
  for (int i = 0; i < files->array_size; i++) {
    matching_line_s** matching_lines = calloc(1, sizeof(matching_line_s*));
    int lines_qtty = 0;
    FILE* file = fopen(files->elements[i], "r");
    if (file == NULL) {
      if (flags->s == 0) {
        fprintf(stderr, "s21_grep: %s: No such file or directory\n",
                files->elements[i]);
        fflush(stderr);
        free(matching_lines);
      }
    } else {
      char c = fgetc(file);
      int line_num = -1;
      while (c != EOF) {
        line_num++;
        char* s = get_long_string(file, &c);
        search_matches_in_line(s, line_num, &lines_qtty, flags, patterns, matching_lines);
        free(s);
      }
      if (flags->l == 1 && lines_qtty) {
        printf("%s\n", files->elements[i]);
      } else if (flags->l == 1 && flags->v == 1 && lines_qtty < line_num) {
        printf("%s\n", files->elements[i]);
      } else if (flags->l == 0 && flags->c == 1) {
        if (flags->h == 0) {
          printf("%s%c", files->elements[i], ':');
        }
        if (flags->v == 0) {
          printf("%d\n", lines_qtty);
        } else {
          printf("%d\n", line_num + 1 - lines_qtty);
        }
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
    attron(COLOR_PAIR (1));
    printf("%.*s", matching_line->eo[i] - matching_line->so[i],
           &s[matching_line->so[i]]);
    attroff(COLOR_PAIR (9));
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
    printf("%s%c", filename, ':');
  }
  if (flags->n != 0 && flags->o == needed_flag) {
    printf("%d%c", line_number + 1, ':');
  }
}