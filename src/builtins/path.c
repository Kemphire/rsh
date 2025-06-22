#include "builtins/path.h"
#include "builtins/exit.h"
#include <common.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>

List *PATH_LIST = NULL;

void add_to_path(char *path) {
  if (PATH_LIST == NULL) {
    PATH_LIST = malloc(sizeof(List));
    if (PATH_LIST == NULL) {
      perror("malloc");
      exit_from_shell(1);
    }
    PATH_LIST->num_ele = 0;
    PATH_LIST->nodes = NULL;
  }

  Node *path_node = malloc(sizeof(Node));
  if (path_node == NULL) {
    perror("malloc");
    exit_from_shell(1);
  }

  path_node->path = path;
  Node **temp_nodes =
      realloc(PATH_LIST->nodes, sizeof(Node *) * (PATH_LIST->num_ele + 1));

  if (temp_nodes == NULL) {
    perror("realloc");
    exit_from_shell(1);
  }
  PATH_LIST->nodes = temp_nodes;
  PATH_LIST->nodes[PATH_LIST->num_ele++] = path_node;
}

void add_many_to_path(char **paths) {
  char **temp = paths;

  // we have no intention to add path as literal path
  temp++;
  while (*temp) {
    int dk = is_dir(*temp);
    if (dk == 1) {
      add_to_path(*temp);
    } else if (dk == 2) {
      WTF("this is not directory");
    } else {
      WTF("Man, what are you passing");
    }
    temp++;
  }
}

void print_path() {
  if (PATH_LIST == NULL) {
    printf("\n");
    return;
  }
  for (int i = 0; i < PATH_LIST->num_ele; i++) {
    printf("%s ", PATH_LIST->nodes[i]->path);
  }
}

int is_dir(char *path) {

  struct stat sb;

  if (stat(path, &sb) == 0) {
    if (S_ISDIR(sb.st_mode)) {
      return 1;
    } else {
      return 2;
    }
  }
  return 0;
}
