#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
int w1;
int w2;
ptrdiff_t stride;
int i;
int j;

static uint8_t *dst_buffer;
static uint8_t *src1_buffer;
static uint8_t *src2_buffer;
static size_t total_size;

void init_vars() {
    total_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime

    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);
    src1_buffer = (uint8_t*)aligned_alloc(32, total_size);
    src2_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!dst_buffer || !src1_buffer || !src2_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t k = 0; k < total_size; k++) {
        src1_buffer[k] = rand() & 0xFF;
        src2_buffer[k] = rand() & 0xFF;
        dst_buffer[k] = 0;
    }

    w1 = 123;
    w2 = 456;
    stride = 8;

    dst = dst_buffer;
    src1 = src1_buffer;
    src2 = src2_buffer;
    i = 0;
    j = 0;
}