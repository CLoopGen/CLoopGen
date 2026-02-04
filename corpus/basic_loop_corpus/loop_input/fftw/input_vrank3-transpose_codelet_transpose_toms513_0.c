#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

char *move;
INT move_size;
INT i;

void init_vars() {
    move_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    move = (char*)calloc(move_size, sizeof(char));
    if (!move) {
        exit(1);
    }
    i = 0;
}