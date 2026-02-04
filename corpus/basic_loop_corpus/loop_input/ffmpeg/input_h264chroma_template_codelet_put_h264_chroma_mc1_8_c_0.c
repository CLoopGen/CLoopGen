#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A = 1;
int B = 1;
int C = 1;
int D = 1;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    size_t buffer_size = total_size + 2 * sizeof(uint8_t) + 2 * stride;

    stride = 1024;
    h = (total_size / stride);

    dst_buffer = aligned_alloc(32, buffer_size);
    src_buffer = aligned_alloc(32, buffer_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(dst_buffer, 0, buffer_size);
    memset(src_buffer, 0, buffer_size);

    for (size_t idx = 0; idx < total_size + stride + 1; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }

    dst = dst_buffer;
    src = src_buffer;
}