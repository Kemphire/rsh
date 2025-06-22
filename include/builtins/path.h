#ifndef PATH_H
#define PATH_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
  char *path;
} Node;

typedef struct {
  Node **nodes;
  size_t num_ele;
} List;

extern List *PATH_LIST;

void add_to_path(char *path);

void add_many_to_path(char **paths);

void print_path();

int is_dir(char *path);
#endif // !PATH_H
