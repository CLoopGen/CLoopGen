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

#define DATA_SIZE (128 << 20) // 128 MB total data
static uint16_t *dst_buffer;
static uint16_t *src_buffer;

void init_vars() {
    // Set scalar values
    A = 42;  // arbitrary value for A
    h = DATA_SIZE / sizeof(uint16_t); // number of elements
    stride = 1; // contiguous stride

    // Allocate aligned memory to prevent access violations
    dst_buffer = aligned_alloc(32, DATA_SIZE);
    src_buffer = aligned_alloc(32, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    // Initialize source data to avoid undefined behavior
    for (int idx = 0; idx < h; idx++) {
        src_buffer[idx] = idx & 0xFFFF;
    }

    // Ensure dst pointer is valid and within allocated range
    dst = dst_buffer;
    src = src_buffer;

    i = 0;
}