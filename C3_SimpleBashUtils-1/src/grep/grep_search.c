#include "grep_search.h"

matching_line_s* lines_init(int line_number) {
  matching_line_s* tmp = (matching_line_s*)calloc(1, sizeof(matching_line_s));
  tmp->line_number = line_number;
  tmp->matches_number = 0;
  tmp->eo = calloc(1, sizeof(int*));
  tmp->so = calloc(1, sizeof(int*));
  return tmp;
}

matching_line_s** add_line(matching_line_s** matching_lines, int* lines_qtty,
                           int line_number) {
  (*lines_qtty)++;
  if (*lines_qtty > 1) {
    matching_lines = (matching_line_s**)realloc(
        matching_lines, *lines_qtty * sizeof(matching_line_s*));
  }
  *(matching_lines + *lines_qtty - 1) = lines_init(line_number);

  return matching_lines;
}

void add_match(matching_line_s* matching_line, int rm_so, int rm_eo) {
  matching_line->matches_number++;
  matching_line->so =
      realloc(matching_line->so, matching_line->matches_number * sizeof(int));
  matching_line->so[matching_line->matches_number - 1] = rm_so;
  matching_line->eo =
      realloc(matching_line->eo, matching_line->matches_number * sizeof(int));
  matching_line->eo[matching_line->matches_number - 1] = rm_eo;
}

void free_matching_lines(matching_line_s** matching_lines, int lines_qtty) {
  for (int i = 0; i < lines_qtty || i < 1; i++) {
    free(matching_lines[i]->eo);
    free(matching_lines[i]->so);
    free(matching_lines[i]);
  }
  free(matching_lines);
}

void find_next_match(regex_t preg, char* s, matching_line_s** matching_lines,
                     int lines_qtty, int offset) {
  size_t nmatch = 1;
  regmatch_t pmatch[1];
  if (!regexec(&preg, s, nmatch, pmatch, 0)) {
    add_match(matching_lines[lines_qtty - 1], pmatch[0].rm_so + offset,
              pmatch[0].rm_eo + offset);
    if (s[pmatch[0].rm_so - 1] != 0) {
      find_next_match(preg, &s[pmatch[0].rm_eo], matching_lines, lines_qtty,
                      offset + pmatch[0].rm_eo);
    }
  }
}

void clean_matches(matching_line_s* matching_line) {
  sort_matches(matching_line);
  for (int i = 1; i < matching_line->matches_number; i++) {
    if (matching_line->so[i] == matching_line->so[i - 1]) {
      if (matching_line->eo[i] > matching_line->eo[i - 1]) {
        delete_match(matching_line, i - 1);
      } else {
        delete_match(matching_line, i);
      }
    } else if (matching_line->so[i] < matching_line->eo[i - 1]) {
      delete_match(matching_line, i);
    }
  }
}

void sort_matches(matching_line_s* matching_line) {
  for (int i = 0; i < matching_line->matches_number; i++) {
    int* max = matching_line->so;
    int* max_e = matching_line->eo;
    for (int j = 0; j < (matching_line->matches_number - i); j++) {
      if (matching_line->so[j] >= *max) {
        max = matching_line->so + j;
        max_e = matching_line->eo + j;
      }
    }
    swap(max, matching_line->so + matching_line->matches_number - i - 1);
    swap(max_e, matching_line->eo + matching_line->matches_number - i - 1);
  }
}

void swap(int* a, int* b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

void delete_match(matching_line_s* matching_line, int n) {
  for (int i = n; i < matching_line->matches_number - 1; i++) {
    matching_line->eo[i] = matching_line->eo[i + 1];
    matching_line->so[i] = matching_line->so[i + 1];
  }
  matching_line->matches_number--;
}

void search_matches_in_line(char* s, int line_num, int* lines_qtty, flags_s* flags, array_s* patterns, matching_line_s** matching_lines) {
  int line_added = 0;
  for (int j = 0; j < patterns->array_size; j++) {
    int regc;
    regex_t preg;
    size_t nmatch = 10;
    regmatch_t pmatch[10];
    if (flags->i == 1) {
      regc = regcomp(&preg, patterns->elements[j], REG_ICASE);
    } else {
      regc = regcomp(&preg, patterns->elements[j], 0);
    }
    if (!regc) {
      if (!regexec(&preg, s, nmatch, pmatch, 0)) {
        if (!line_added) {
          matching_lines =
              add_line(matching_lines, lines_qtty, line_num);
          line_added = 1;
        }
        add_match(matching_lines[*lines_qtty - 1], pmatch[0].rm_so,
                  pmatch[0].rm_eo);
        if (s[pmatch[0].rm_eo - 1] != 0) {
          find_next_match(preg, &s[pmatch[0].rm_eo], matching_lines,
                          *lines_qtty, pmatch[0].rm_eo);
        }
      }
    }
    regfree(&preg);
  }
  if (*lines_qtty > 0) {
    clean_matches(matching_lines[*lines_qtty - 1]);
  }
}