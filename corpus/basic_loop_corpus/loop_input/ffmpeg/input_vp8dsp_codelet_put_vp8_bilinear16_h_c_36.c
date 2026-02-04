#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstride;
uint8_t *src;
ptrdiff_t sstride;
int h;
int a;
int b;
int x;
int y;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const int width = 16;
    h = 40000;
    a = 5;
    b = 3;
    dstride = 16;
    sstride = 17;

    size_t dst_size = (size_t)h * dstride;
    size_t src_size = (size_t)h * sstride;

    dst_buffer = aligned_alloc(32, dst_size);
    src_buffer = aligned_alloc(32, src_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = dst_buffer;
    src = src_buffer;

    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }
    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
}