#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *a_data[4];
int a_linesize[4];
uint8_t *b_data[4];
int b_linesize[4];
int x;
int y;
int d;
int ret;

static uint8_t *alloc_aligned_size(int size) {
    uint8_t *ptr = aligned_alloc(32, size);
    return ptr;
}

void init_vars() {
    const int block_size = 4;
    const int total_size = 1 << 20; // ~1MB per plane

    for (int i = 0; i < 4; i++) {
        a_linesize[i] = block_size;
        b_linesize[i] = block_size;

        a_data[i] = alloc_aligned_size(total_size);
        b_data[i] = alloc_aligned_size(total_size);

        for (int j = 0; j < block_size * block_size; j++) {
            a_data[i][j] = rand() & 0xFF;
            b_data[i][j] = rand() & 0xFF;
        }
    }

    x = 0;
    y = 0;
    d = 0;
    ret = 0;
}