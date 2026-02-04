#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride;
uint8_t *src1;
uint8_t *src2;
int V;

static uint8_t *buffer1;
static uint8_t *buffer2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    stride = 16;
    k = 1;
    V = 0;

    buffer1 = (uint8_t*)aligned_alloc(32, data_size);
    buffer2 = (uint8_t*)aligned_alloc(32, data_size);

    if (!buffer1 || !buffer2) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        buffer1[i] = (uint8_t)(i & 0xFF);
        buffer2[i] = (uint8_t)((i + 128) & 0xFF);
    }

    src1 = buffer1 + 128;
    src2 = buffer2 + data_size - 128 - stride * 8;
}