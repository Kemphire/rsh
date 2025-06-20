#include "../exec/execute_commands_with_arg.c"
#include "../parse/split_lines_to_args.c"
#include "prompt.h"
#include "read_input_line.c"
#include <stdio.h>
#include <stdlib.h>

int handle_interactive_mode() {
  int status = 0;
  char *line;
  char **args;
  do {
    status == 0 ? printf(PROMPT) : printf(PROMPT);
    line = read_input_line();
    if (line == NULL) {
      putchar('\n');
      free(line);
      exit(EXIT_SUCCESS);
    }

    args = split_lines_to_args(&line);
    status = execute_commands_with_arg(args);

  } while (1);
}
