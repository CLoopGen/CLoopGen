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
    w = 4096;
    h = 4096;

    size_t total_size = (size_t)w * h;
    buf = (IDWTELEM*)aligned_alloc(32, total_size * sizeof(IDWTELEM));
    if (!buf) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        buf[i] = rand() % 256;
    }
}