#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int block_size = 65536;
float *dst;
uint16_t *src;
int j;

void init_vars() {
    dst = (float *)aligned_alloc(32, block_size * sizeof(float));
    src = (uint16_t *)aligned_alloc(32, block_size * sizeof(uint16_t));

    for (int i = 0; i < block_size; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }

    for (int i = 0; i < block_size; i++) {
        dst[i] = 0.0f;
    }
}