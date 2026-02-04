#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int len;
int8_t **shift;
int i;
int8_t *src2;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec runtime

    dst = (uint8_t*)aligned_alloc(32, len * sizeof(uint8_t));
    src2 = (int8_t*)aligned_alloc(32, len * sizeof(int8_t));

    shift = (int8_t**)aligned_alloc(32, 3 * sizeof(int8_t*));
    shift[0] = (int8_t*)aligned_alloc(32, len * sizeof(int8_t));
    shift[1] = (int8_t*)aligned_alloc(32, len * sizeof(int8_t));
    shift[2] = (int8_t*)aligned_alloc(32, len * sizeof(int8_t));

    for (i = 0; i < len; i++) {
        src2[i] = rand() % 256 - 128;
        shift[0][i] = rand() % 256 - 128;
        shift[1][i] = rand() % 256 - 128;
        shift[2][i] = rand() % 256 - 128;
        dst[i] = 0;
    }
}