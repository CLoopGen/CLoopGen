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

#define DATA_SIZE (128 << 20) // 128 MB target data size

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    h = 4096;
    a = 3;
    b = 5;
    x = 0;
    y = 0;

    sstride = 4096;
    dstride = 4096;

    size_t src_size = (size_t)h * (size_t)sstride + 5;
    size_t dst_size = (size_t)h * (size_t)dstride;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}