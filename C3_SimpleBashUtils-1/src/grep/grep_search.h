#ifndef GREP_SEARCH_H
#define GREP_SEARCH_H

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "grep_parcer.h"

typedef struct matching_line {
  int line_number;
  int matches_number;
  int* eo;
  int* so;
} matching_line_s;

matching_line_s* lines_init(int line_number);
matching_line_s** add_line(matching_line_s** matching_lines, int* lines_qtty,
                           int line_number);
void add_match(matching_line_s* matching_line, int rm_so, int rm_eo);
void free_matching_lines(matching_line_s** matching_lines, int lines_qtty);
void find_next_match(regex_t preg, char* s, matching_line_s** matching_lines,
                     int lines_qtty, int offset);
void clean_matches(matching_line_s* matching_line);
void sort_matches(matching_line_s* matching_line);
void swap(int* a, int* b);
void delete_match(matching_line_s* matching_line, int n);
void search_matches_in_line(char* s, int line_num, int* lines_qtty, flags_s* flags, array_s* patterns, matching_line_s** matching_lines);

#endif