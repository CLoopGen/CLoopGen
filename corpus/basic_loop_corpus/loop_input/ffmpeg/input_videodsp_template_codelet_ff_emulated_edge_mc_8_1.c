#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int block_w;
int x;
int end_x;
uint8_t *bufp;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB for ~0.01 sec runtime on modern CPU

    bufp = (uint8_t*)aligned_alloc(32, data_size);
    if (!bufp) {
        exit(1);
    }

    block_w = data_size - 1;
    end_x = 1000;

    for (size_t i = 0; i < data_size; i++) {
        bufp[i] = (uint8_t)(i & 0xFF);
    }
}