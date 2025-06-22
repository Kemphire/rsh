#include "builtins/cd.h"
#include "common.h"
#include "exec/execute_commands_with_arg.h"
#include "input/prompt.h"
#include "input/read_input_line.h"
#include "parse/split_lines_to_args.h"
#include "utils/free_resource.h"
#include <stdio.h>
#include <stdlib.h>

int handle_interactive_mode() {
  int status = 0;
  char *line;
  char **args;
  do {
    initalize_cdir();
    PRINT_CDIR(CWD);
    if (status == 0)
      PRINT_SUCCESS(PROMPT);
    else
      PRINT_WARN(PROMPT);

    line = read_input_line();
    if (line == NULL) {
      putchar('\n');
      free(line);
      exit(EXIT_SUCCESS);
    }

    args = split_lines_to_args(&line);

    // free up the line
    free(line);

    status = execute_commands_with_arg(args);

    // free up the args
    free_args(args);

  } while (1);
}
