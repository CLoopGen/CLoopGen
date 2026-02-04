#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;

static uint8_t *dst_buf;
static uint8_t *src_buf;

void init_vars() {
    // Set parameters for ~0.01 seconds runtime on modern CPU
    // Assume moderate operation count; each iteration does a few integer ops
    // Aim for about 10-20 million iterations to fit time target

    h = 16777216;  // 2^24 iterations (~16M), reasonable for ~0.01s with optimization
    stride = 1;    // unit stride

    A = 42;  // arbitrary non-zero coefficient

    // Allocate buffers with padding to prevent overflow based on stride and h
    size_t buf_size = (h - 1) * stride + 1;

    dst_buf = aligned_alloc(32, buf_size);
    src_buf = aligned_alloc(32, buf_size);

    if (!dst_buf || !src_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero (or some deterministic values)
    for (size_t idx = 0; idx < buf_size; idx++) {
        dst_buf[idx] = 0;
        src_buf[idx] = (uint8_t)(idx & 0xFF);
    }

    // Initialize pointers
    dst = dst_buf;
    src = src_buf;
}