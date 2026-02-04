#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
int w;
long i;

static uint8_t *alloc_zeroed(size_t size) {
    uint8_t *ptr = (uint8_t *)calloc(1, size);
    return ptr;
}

void init_vars() {
    w = 64 * 1024 * 1024; // 64 million elements ~ 64MB per array

    dst = alloc_zeroed(w * sizeof(uint8_t));
    src1 = alloc_zeroed(w * sizeof(uint8_t));
    src2 = alloc_zeroed(w * sizeof(uint8_t));

    for (int j = 0; j < w; j++) {
        src1[j] = (uint8_t)(j & 0xFF);
        src2[j] = (uint8_t)((j + 123) & 0xFF);
    }

    i = 0;
}