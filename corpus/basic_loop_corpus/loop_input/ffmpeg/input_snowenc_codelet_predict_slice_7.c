#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *buf;
int mb_y;
int x;
int y;
int block_h;
int w;
int h;

void init_vars() {
    block_h = 16;
    mb_y = 0;
    w = 2048;
    h = 2048;

    size_t total_size = w * (size_t)h;
    buf = (IDWTELEM *)calloc(total_size, sizeof(IDWTELEM));
    if (!buf) {
        exit(1);
    }
}