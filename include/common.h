#ifndef COMMON_H
#define COMMON_H

#include "input/prompt.h"
#include <stdio.h>

#define BUF_SIZE 10
#define BUILTINS_SIZE 3

#define RED "\033[91m"
#define NORMAL "\033[0m"
#define GREEN "\033[92m"

#define PRINT_WARN(str)                                                        \
  do {                                                                         \
    printf("%s%s%s", RED, str, NORMAL);                                        \
  } while (0)

#define PRINT_SUCCESS(str)                                                     \
  do {                                                                         \
    printf("%s%s%s", GREEN, str, NORMAL);                                      \
  } while (0)

#define PRINT_CDIR(CWD)                                                        \
  do {                                                                         \
    printf("\n%s\n", CWD);                                                     \
  } while (0)

#define WTF(MSG)                                                               \
  do {                                                                         \
    printf("%s%s%s\n", RED, MSG, NORMAL);                                      \
  } while (0)

#endif // !COMMON_H
