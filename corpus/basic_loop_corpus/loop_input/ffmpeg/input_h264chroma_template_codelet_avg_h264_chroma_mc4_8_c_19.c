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
int E;
ptrdiff_t step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    A = 17;
    E = 31;
    h = 65536;
    stride = 4096;
    step = 2048;

    size_t total_size = (size_t)h * (size_t)stride;
    dst_buffer = aligned_alloc(32, total_size);
    src_buffer = aligned_alloc(32, total_size + step + 8);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = dst_buffer;
    src = src_buffer;

    for (size_t i = 0; i < total_size; ++i) {
        dst_buffer[i] = (uint8_t)(i % 256);
    }
    for (size_t i = 0; i < total_size + step + 8; ++i) {
        src_buffer[i] = (uint8_t)((i * 31) % 256);
    }
}