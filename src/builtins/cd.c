#include <builtins/cd.h>
#include <builtins/exit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *CWD = NULL;

int cd(char *path) {
  int status = chdir(path);
  if (status < 0) {
    return -1;
  }
  change_cwd(path);
  return 0;
}

char *get_current_dir() {
  char *buf = malloc(sizeof(char) * PATH_SIZE);
  size_t size = PATH_SIZE;

  while (getcwd(buf, size) == NULL) {
    size *= 2;
    char *temp;
    temp = realloc(buf, sizeof(char) * size);
    if (temp == NULL) {
      perror("realloc");
      exit_from_shell(1);
    }
    buf = temp;
  }

  return buf;
}

void change_cwd(char *path) { CWD = strdup(path); }

void initalize_cdir() {
  char *path = get_current_dir();
  CWD = path;
}
