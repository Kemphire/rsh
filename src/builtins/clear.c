#include "builtins/clear.h"
#include <stdio.h>
#include <unistd.h>

void clear_screen() {
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
