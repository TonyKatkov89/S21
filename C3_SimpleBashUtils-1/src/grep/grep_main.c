#include "grep_main.h"

int main(int argc, char* argv[]) {
  flags_s* flags = flags_init();
  array_s* patterns = array_init();
  array_s* files = array_init();
  char last_flag = '0';
  int error = 0;

  //initscr();

  for (int i = 1; i < argc && !error; i++) {
    error = parce_flags(argv[i], flags);
  }

  for (int i = 1; i < argc && !error; i++) {
    error =
        parce_files_and_patterns(argv[i], flags, patterns, files, &last_flag);
  }

  if (files->array_size < 2) {
    flags->h = 1;
  }

  if (!error) {
    print(patterns, files, flags);
  }

  free(flags);
  for (int i = 0; i < patterns->array_size; i++) {
    free(patterns->elements[i]);
  }
  free(patterns->elements);
  free(patterns);
  for (int i = 0; i < files->array_size; i++) {
    free(files->elements[i]);
  }
  free(files->elements);
  free(files);

  refresh();
  //endwin();

  return error;
}