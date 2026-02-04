#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE 25

uint8_t *c[ARRAY_SIZE];
uint8_t *src;
int stride;
int x;
int w;
int y;
int h;
int bpc;
int i;

void init_vars() {
    w = 1024;
    h = 1024;
    bpc = 3;
    stride = w * bpc;
    x = w / 2;
    y = h / 2;

    size_t src_size = (size_t)stride * h;
    src = (uint8_t*)aligned_alloc(64, src_size);
    if (!src) {
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; ++idx) {
        src[idx] = (uint8_t)(idx % 256);
    }

    for (int j = 0; j < ARRAY_SIZE; ++j) {
        c[j] = NULL;
    }
}