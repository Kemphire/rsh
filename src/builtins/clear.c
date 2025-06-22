#include <builtins/clear.h>
#include <stdio.h>

void clear_screen() { printf("%s", CLEAR_CODE); }
