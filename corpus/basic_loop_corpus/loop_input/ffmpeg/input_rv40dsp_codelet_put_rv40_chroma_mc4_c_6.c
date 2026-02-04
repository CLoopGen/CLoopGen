#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int i;
int bias;
int E;
ptrdiff_t step;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;
static ptrdiff_t buffer_size;

void init_vars() {
    buffer_size = 16 * 1024 * 1024; // 16 MB of data
    internal_src_buffer = (uint8_t *)aligned_alloc(32, buffer_size);
    internal_dst_buffer = (uint8_t *)aligned_alloc(32, buffer_size);

    if (!internal_src_buffer || !internal_dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        internal_src_buffer[i] = rand() & 0xFF;
        internal_dst_buffer[i] = 0;
    }

    src = internal_src_buffer;
    dst = internal_dst_buffer;

    stride = 16;
    step = 8;
    h = 1000000;
    A = 50;
    E = 20;
    bias = 32;
    i = 0;
}