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
    const size_t data_size = 256 * 1024 * sizeof(int16_t);
    block = aligned_alloc(32, data_size);
    if (!block) {
        exit(1);
    }
    for (size_t idx = 0; idx < 256 * 1024; idx++) {
        block[idx] = (int16_t)(idx % 32767);
    }
}