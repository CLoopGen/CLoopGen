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

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    A = 42;
    h = 1 << 18;
    stride = 16;

    size_t total_size = (size_t)h * (size_t)stride;

    dst_buffer = aligned_alloc(32, total_size);
    src_buffer = aligned_alloc(32, total_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        dst_buffer[idx] = (uint8_t)(idx % 256);
        src_buffer[idx] = (uint8_t)((2 * idx + 17) % 256);
    }

    dst = dst_buffer;
    src = src_buffer;
}