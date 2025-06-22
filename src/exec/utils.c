#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

const char *ALL_BULTINS[BUILTINS_SIZE] = {"cd", "exit", "path"};

bool check_length(char **args) {
  int len = 0;

  char **d = args;

  while (*d) {
    len++;
    d++;
  }

  return len > 0;
}

int wait_for_child_and_exit(pid_t child) {
  int status;
  if (waitpid(child, &status, 0) == -1)
    return -2;

  if (WIFEXITED(status)) {
    int code = WEXITSTATUS(status);
    if (code == 127) {
      return -1;
    }
  } else {
    return -2;
  }
  return 0;
}

bool is_builtin(char **args) {
  for (int i = 0; i < BUILTINS_SIZE; i++) {
    if (strcmp(ALL_BULTINS[i], args[0]) == 0)
      return true;
  }
  return false;
}
