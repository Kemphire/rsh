#include "builtins/cd.h"
#include "builtins/exit.h"
#include "builtins/path.h"
#include "exec/not_builtin.h"
#include "exec/utils.h"
#include "utils/some_common_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// returns 0 when exited successfully, otherwise non zero
int execute_commands_with_arg(char **args) {
  // support for single command first

  if (!check_length(args)) {
    return 0;
  }

  if (is_builtin(args)) {
    if (strcmp("exit", args[0]) == 0) {
      if (count_the_number_of_args(args) == 1)
        exit_from_shell(0);
      else
        printf("wrong use of exit\n");
    } else if (strcmp("cd", args[0]) == 0) {
      if (count_the_number_of_args(args) == 2) {
        int status = cd(args[1]);
        if (status != 0) {
          WTF("bro you'r not allowed to visit there");
          return -9;
        }
        return 0;
      } else {
        printf("usage: cd [path]");
        return -7;
      }
    } else {
      if (count_the_number_of_args(args) < 2) {
        printf("usage: path [path1] [path2] [...]");
        return -10;
      } else {
        add_many_to_path(args);
        print_path();
        return 0;
      }
      return 1;
    }
  } else {
    return execute_not_builtin(args);
  }
  // here the code will most prolly will never reach
  return -5;
}
