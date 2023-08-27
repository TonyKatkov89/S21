#ifndef CAT_PARCER_H
#define CAT_PARCER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/array.h"

typedef struct flags {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags_s;

flags_s* initializing();
int parce_argument(char* arg, flags_s* flags, array_s* files_to_print);
char trigger_flags(char* arg, flags_s* flags);
void add_to_print(char* arg, char*** files_to_print, int* files_num);

#endif