#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride;
uint16_t *src1;
uint16_t *src2;
int V;

static uint16_t *buffer1;
static uint16_t *buffer2;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 524,288 elements per array (since uint16_t is 2 bytes)

    buffer1 = aligned_alloc(32, data_size);
    buffer2 = aligned_alloc(32, data_size);

    for (size_t i = 0; i < data_size / sizeof(uint16_t); ++i) {
        buffer1[i] = rand() % 65536;
        buffer2[i] = rand() % 65536;
    }

    stride = 16;
    k = 0;
    src1 = buffer1 + 100;
    src2 = buffer2 + (data_size / sizeof(uint16_t)) - 100 - stride * 8;
    V = 0;
}