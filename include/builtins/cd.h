#ifndef CD_H

#define CD_H

#define PATH_SIZE 100

int cd(char *path);

extern char *CWD;

char *get_current_dir();

void change_cwd(char *path);

void initalize_cdir();

#endif // !CD_H
