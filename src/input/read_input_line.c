#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *read_input_line() {
  char *line = NULL;
  size_t size = 0;
  ssize_t nread;

  // if ((nread = getline(&line, &size, stdin)) != -1) {
  // }
  // if(nread == 0 && feof(stdin)){}
  nread = getline(&line, &size, stdin);
  if (nread == -1) {
    return NULL;
  }

  // We are replacing new line with '\0' in order to parse it correctly
  if (nread > 0 && line[nread - 1] == '\n') {
    line[nread - 1] = '\0';
  }
  return line;
}
