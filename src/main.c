#include "./input/handle_batch_mode.c"
#include "./input/handle_interactive_mode.c"
#include "./input/prompt.h"
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
  return EXIT_SUCCESS;
}
