#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int block_size;
float *dst;
uint8_t *src;
int j;

void init_vars() {
    block_size = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec on typical CPU

    dst = (float *)aligned_alloc(32, block_size * sizeof(float));
    src = (uint8_t *)aligned_alloc(32, block_size * sizeof(uint8_t));

    for (int i = 0; i < block_size; i++) {
        src[i] = (uint8_t)(i % 251); // prime modulus to vary values
    }

    for (int i = 0; i < block_size; i++) {
        dst[i] = 0.0f;
    }
}