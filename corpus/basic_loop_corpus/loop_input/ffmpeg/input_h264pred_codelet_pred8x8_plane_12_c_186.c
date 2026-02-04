#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 16;
uint16_t * src0;
uint16_t * src1;
uint16_t * src2;
int H = 0;
int V = 0;

static uint16_t * buffer = NULL;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (adjustable)
    buffer = (uint16_t*)aligned_alloc(32, data_size);
    if (!buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(uint16_t); ++i) {
        buffer[i] = (uint16_t)(i % 32768);
    }

    src0 = buffer + 4; // Ensure that src0[-k] and src0[k] are valid for k in [2,4]
    src1 = buffer + 16;
    src2 = buffer + data_size / sizeof(uint16_t) - 16;

    stride = 8;
}