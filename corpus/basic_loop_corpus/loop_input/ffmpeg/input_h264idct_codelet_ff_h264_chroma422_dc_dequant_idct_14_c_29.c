#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride = 64;
int xStride = 1;
int i = 0;
unsigned int temp[8];

int32_t *block;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(int32_t);
    block = aligned_alloc(32, data_size);
    if (!block) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(int32_t); ++idx) {
        block[idx] = (int32_t)(idx % 256);
    }
}