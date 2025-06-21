#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

bool check_length(char **args) {
  int len = 0;

  char **d = args;

  while (*d) {
    len++;
    d++;
  }

  printf("Len of args are %d\n", len);
  return len > 0;
}

// returns 0 when exited successfully, otherwise non zero
int execute_commands_with_arg(char **args) {

  // support for single command first

  if (!check_length(args)) {
    return 2;
  }

  pid_t child = fork();

  if (child < 0) {
    perror("fork");
    return 1;
  }

  if (child == 0) {

    execvp(args[0], args);

    perror("execvp");
    exit(127);
  } else {
    int status;
    if (waitpid(child, &status, 0) == -1)
      return -2;

    if (WIFEXITED(status)) {
      int code = WEXITSTATUS(status);
      if (code == 127) {
        return -1;
      }
    } else
      return -2;
  }
  return 0;
}
