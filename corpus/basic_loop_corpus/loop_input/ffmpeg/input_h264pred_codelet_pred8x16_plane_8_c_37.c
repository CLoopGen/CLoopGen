#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride;
uint8_t * src0;
uint8_t * src1;
uint8_t * src2;
int H;
int V;

static uint8_t *buffer_src0;
static uint8_t *buffer_src1;
static uint8_t *buffer_src2;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    stride = 1024;

    buffer_src0 = (uint8_t*)aligned_alloc(32, data_size);
    buffer_src1 = (uint8_t*)aligned_alloc(32, data_size);
    buffer_src2 = (uint8_t*)aligned_alloc(32, data_size);

    for (int i = 0; i < data_size; ++i) {
        buffer_src0[i] = rand() % 256;
        buffer_src1[i] = rand() % 256;
        buffer_src2[i] = rand() % 256;
    }

    src0 = buffer_src0 + 4; // ensure at least 4 elements before and after valid access
    src1 = buffer_src1 + stride * 2;
    src2 = buffer_src2 + data_size - stride * 2 - 1;

    H = 0;
    V = 0;
}