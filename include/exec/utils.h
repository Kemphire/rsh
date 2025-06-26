#ifndef UTILS_H
#define UTILS_H

#include "../common.h"
#include <stdbool.h>
#include <unistd.h>

extern const char *ALL_BULTINS[];

bool check_length(char **args);

int length_of_args(char **args);

int wait_for_child_and_exit(pid_t child);

bool is_builtin(char **args);

bool redirection(char **args);
#endif // !UTILS_H
