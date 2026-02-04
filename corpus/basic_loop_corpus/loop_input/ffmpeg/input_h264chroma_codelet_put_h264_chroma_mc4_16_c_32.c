#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;

#define DATA_SIZE (128 << 20)  // 128 MB total data size
#define ELEMENTS (DATA_SIZE / sizeof(uint16_t))

static uint16_t *dst_buffer;
static uint16_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 42;  // arbitrary non-zero coefficient
    h = 8192;  // number of iterations
    stride = 4;  // step by 4 uint16_t elements per iteration

    // Allocate large buffers to ensure meaningful runtime (~0.01 sec)
    dst_buffer = aligned_alloc(32, DATA_SIZE);
    src_buffer = aligned_alloc(32, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data with non-zero values
    for (int idx = 0; idx < ELEMENTS; idx++) {
        src_buffer[idx] = (uint16_t)(idx % 65535);
    }

    // Ensure dst has valid memory range
    for (int idx = 0; idx < ELEMENTS; idx++) {
        dst_buffer[idx] = 0;
    }

    // Set pointers used in loop
    dst = dst_buffer;
    src = src_buffer;
}