#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride = 16;
int xStride = 1;
int i;

unsigned int temp[8];

int16_t *block;

void init_vars() {
    const size_t block_size = 256 * 1024 * 1024; // 256 MB of int16_t data
    block = (int16_t*)aligned_alloc(32, block_size * sizeof(int16_t));
    if (!block) {
        fprintf(stderr, "Failed to allocate block\n");
        exit(1);
    }

    for (size_t idx = 0; idx < block_size; ++idx) {
        block[idx] = (int16_t)(idx % 512 - 256);
    }
}