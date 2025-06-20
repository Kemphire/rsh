#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 10

bool is_no_all_whitespace(const char *str) {
  while (*str) {
    if (!isspace(*str)) {
      return true;
    }
    str++;
  }
  return false;
}

char **split_lines_to_args(char **line) {
  int buf_size = BUF_SIZE;
  char **arg_list = malloc(sizeof(char *) * buf_size);
  int no_arg = 0;

  char *token;

  while ((token = strsep(line, " ")) != NULL) {
    if (is_no_all_whitespace(token)) {
      arg_list[no_arg] = token;
      no_arg++;
    }
    if (no_arg >= buf_size) {
      buf_size *= 2;

      char **toks = realloc(arg_list, sizeof(char *) * buf_size);
      if (!toks) {
        fprintf(stderr, "rsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
  arg_list[no_arg] = NULL;

  char **d = arg_list;

  while (*d) {
    printf("%s\n", *d);
    d++;
  }

  return arg_list;
}
