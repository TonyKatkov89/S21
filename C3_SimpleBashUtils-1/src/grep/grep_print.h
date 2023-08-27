#ifndef GREP_PRINT_H
#define GREP_PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "grep_parcer.h"
#include "grep_search.h"

void print(array_s* patterns, array_s* files, flags_s* flags);
void print_file(matching_line_s** matching_lines, FILE* file, char* filename,
                int lines_qtty, flags_s* flags);
void print_line(matching_line_s* matching_line, char* s, flags_s* flags,
                char* filename);
void print_file_and_line(char* filename, int line_number, flags_s* flags,
                         int needed_flag);

#endif