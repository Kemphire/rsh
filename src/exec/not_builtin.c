#include "common.h"
#include "exec/utils.h"
#include "utils/free_resource.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int execute_redirection(char **args) {

  int len_args = length_of_args(args);

  if (strcmp(args[len_args - 2], ">") != 0) {
    WTF("this is not a correct redirection command\n");
    return -20;
  }

  const char *file_name = args[len_args - 1];

  pid_t child = fork();

  if (child < 0) {
    perror("fork");
    return 1;
  }

  if (child == 0) {
    int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
      WTF("file not opened\n");
      return -29;
    }
    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);

    // we no longer the fd, because the file now has two new descriptors
    // associated with it
    close(fd);

    int new_arg_len = len_args - 2;

    char *new_args[new_arg_len + 1];

    for (int i = 0; i < new_arg_len; i++) {
      new_args[i] = args[i];
    }

    new_args[new_arg_len] = NULL;

    execvp(new_args[0], new_args);
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
