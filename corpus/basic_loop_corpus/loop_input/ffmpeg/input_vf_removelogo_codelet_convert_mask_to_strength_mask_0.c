#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *data;
int linesize;
int w;
int h;
int min_val;
int x;
int y;

void init_vars() {
    w = 4096;
    h = 4096;
    linesize = w;
    min_val = 128;

    data = (uint8_t*)aligned_alloc(32, (size_t)h * linesize);
    if (!data) {
        exit(1);
    }

    for (int i = 0; i < h * linesize; i++) {
        data[i] = rand() % 256;
    }
}