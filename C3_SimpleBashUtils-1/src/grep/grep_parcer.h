#ifndef GREP_PARCER_H
#define GREP_PARCER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "../common/array.h"

typedef struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} flags_s;

flags_s* flags_init();
int parce_flags(char* arg, flags_s* flags);
int parce_files_and_patterns(char* arg, flags_s* flags, array_s* patterns,
                             array_s* files, char* last_flag);
char trigger_flags(char* arg, flags_s* flags);
void add_to_print(char* arg, char*** files_to_print, int* files_num);
int file_to_array(char* arg, array_s* patterns);
char* get_long_string(FILE* file, char* c);

#endif