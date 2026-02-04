#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride = 16;
int xStride = 1;
int i;

unsigned int temp[8];

int32_t *block;

void init_vars() {
    const size_t block_size = 256 * 1024 * 1024; // 256 MB of data
    block = aligned_alloc(32, block_size);
    if (!block) {
        fprintf(stderr, "Failed to allocate block\n");
        exit(1);
    }

    for (size_t idx = 0; idx < block_size / sizeof(int32_t); idx++) {
        block[idx] = rand() % 1000;
    }
}