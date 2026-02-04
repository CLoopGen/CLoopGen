#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *ptr;
uint8_t planes[4][1024];
int i;

static uint8_t *buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    buffer = aligned_alloc(32, data_size);
    if (!buffer) {
        exit(1);
    }

    ptr = buffer;
    for (size_t idx = 0; idx < data_size; idx++) {
        buffer[idx] = rand() % 256;
    }

    for (int p = 0; p < 4; p++) {
        for (int j = 0; j < 1024; j++) {
            planes[p][j] = 0;
        }
    }

    i = 0;
}