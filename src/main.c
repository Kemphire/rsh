#include "input/handle_batch_mode.h"
#include "input/handle_interactive_mode.h"
#include "input/prompt.h"
#include "utils/free_resource.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    handle_interactive_mode();
  } else if (argc >= 2 && strcmp(argv[1], "--version") == 0) {
    printf(VERSION);
  } else {
    handle_batch_mode(argv[1]);
  }
  free_all_resources();
  return EXIT_SUCCESS;
}
