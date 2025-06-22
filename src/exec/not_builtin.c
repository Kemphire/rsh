#ifndef NOT_BUILTIN_C

#include "exec/utils.h"
#include "utils/free_resource.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int execute_not_builtin(char **args) {

  pid_t child = fork();

  if (child < 0) {
    perror("fork");
    return 1;
  }

  if (child == 0) {
    execvp(args[0], args);
    perror("execvp");
    free_all_resources();
    // free all the args here too, because it's being copied here from the
    // parent process
    free(args);
    exit(127);
  } else {
    return wait_for_child_and_exit(child);
  }
  return 0;
}
#endif /* ifndef NOT_BUILTIN_C */
