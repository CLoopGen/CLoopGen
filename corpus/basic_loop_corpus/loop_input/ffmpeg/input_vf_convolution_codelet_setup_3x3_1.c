#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB

uint8_t *src;
uint8_t **c;
int stride;
int x;
int w;
int y;
int h;
int bpc;
int i;

void init_vars() {
    w = 4096;
    h = 8192;
    bpc = 4;
    x = w / 2;
    y = h / 2;
    stride = w * bpc;

    src = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    c = (uint8_t**)calloc(9, sizeof(uint8_t*));

    if (!src || !c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src[idx] = (uint8_t)(idx % 256);
    }
}