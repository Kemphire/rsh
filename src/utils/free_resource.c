#include "builtins/cd.h"
#include "builtins/path.h"
#include "input/prompt.h"
#include <stdlib.h>

void free_args(char **args) { free(args); }

void free_up_the_cdir() {
  if (CWD) {
    free(CWD);
    CWD = NULL;
  }
}

void free_up_the_path_list() {
  if (PATH_LIST == NULL) {
    return;
  }
  for (size_t i = 0; i < PATH_LIST->num_ele; i++) {
    if (PATH_LIST->nodes[i]) {
      free(PATH_LIST->nodes[i]);
    }
  }
  free(PATH_LIST);
}

void free_all_resources() {
  free_up_the_cdir();
  free_up_the_path_list();
}
