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
    h = 1080;
    w = 1920;

    size_t total_size = (size_t)h * w;
    buf = (IDWTELEM *)calloc(total_size, sizeof(IDWTELEM));
    if (!buf) {
        exit(1);
    }
}