#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride;
uint16_t * src0;
uint16_t * src1;
uint16_t * src2;
int H;
int V;

static uint16_t *buffer_src0;
static uint16_t *buffer_src1;
static uint16_t *buffer_src2;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (~65k elements for uint16_t)

    buffer_src0 = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    buffer_src1 = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    buffer_src2 = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));

    if (!buffer_src0 || !buffer_src1 || !buffer_src2) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        buffer_src0[i] = (uint16_t)(i % 32768);
        buffer_src1[i] = (uint16_t)((i + 100) % 32768);
        buffer_src2[i] = (uint16_t)((i + 200) % 32768);
    }

    src0 = buffer_src0 + 8;
    src1 = buffer_src1 + 8;
    src2 = buffer_src1 + data_size - 9;

    stride = 1;
    H = 0;
    V = 0;
}