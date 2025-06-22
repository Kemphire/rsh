#include "utils/free_resource.h"
#include <stdio.h>
#include <stdlib.h>

void exit_from_shell(int code) {
  free_all_resources();
  printf("\n");
  exit(code);
}
