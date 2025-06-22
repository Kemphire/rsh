#include <stdio.h>

int count_the_number_of_args(char **args) {
  if (args == NULL) {
    return 0;
  }
  char **temp = args;
  int count = 0;

  while (*temp) {
    temp++;
    count++;
  }
  return count;
}
