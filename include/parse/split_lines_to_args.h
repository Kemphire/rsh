#ifndef SPLIT_LINES_TO_ARGS
#define SPLIT_LINES_TO_ARGS

#include <stdbool.h>

bool is_no_all_whitespace(const char *str);

char **split_lines_to_args(char **line);
#endif // !SPLIT_LINES_TO_ARGS
