#include "cat_parcer.h"
#include "cat_print.h"

int main(int argc, char* argv[]) {
  flags_s* flags = initializing();
  array_s* files_to_print = array_init();
  int error = 0;

  for (int i = 1; i < argc && !error; i++) {
    error = parce_argument(argv[i], flags, files_to_print);
  }

  if (!error) {
    print_files(files_to_print, flags);
  }

  free(flags);
  for (int i = 0; i < files_to_print->array_size; i++) {
    free(files_to_print->elements[i]);
  }
  free(files_to_print->elements);
  free(files_to_print);

  return error;
}