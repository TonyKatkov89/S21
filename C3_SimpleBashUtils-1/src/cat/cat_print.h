#ifndef CAT_PRINT_H
#define CAT_PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cat_parcer.h"

void print_files(array_s* files_to_print, flags_s* flags);
void print_line_number(char c1, flags_s* flags, int* line_num);
void print_non_printable(char non_printable_char, flags_s* flags);
int is_char_non_printable(char c);

#endif