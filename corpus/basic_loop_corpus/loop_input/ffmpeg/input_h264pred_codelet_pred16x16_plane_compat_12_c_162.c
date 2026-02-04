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
static size_t total_size = 64 * 1024 * 1024; // 64 MB of data

void init_vars() {
    stride = 1024;
    H = 0;
    V = 0;

    buffer_src0 = (uint16_t*)aligned_alloc(32, total_size);
    buffer_src1 = (uint16_t*)aligned_alloc(32, total_size);
    buffer_src2 = (uint16_t*)aligned_alloc(32, total_size);

    for (size_t i = 0; i < total_size / sizeof(uint16_t); ++i) {
        buffer_src0[i] = rand() % 1000;
        buffer_src1[i] = rand() % 1000;
        buffer_src2[i] = rand() % 1000;
    }

    src0 = buffer_src0 + 8;
    src1 = buffer_src1 + 8 * stride;
    src2 = buffer_src2 + 8 * stride;
}