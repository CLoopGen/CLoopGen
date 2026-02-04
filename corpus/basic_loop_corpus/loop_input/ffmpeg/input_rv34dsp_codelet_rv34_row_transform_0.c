#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int temp[16];

int16_t *block;
int i;

void init_vars() {
    const size_t block_size = 256 * 1024 * sizeof(int16_t);
    block = aligned_alloc(32, block_size);
    if (!block) {
        exit(1);
    }
    for (size_t idx = 0; idx < 256 * 1024; idx++) {
        block[idx] = rand() % 100;
    }
}