#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstride;
uint8_t *src;
ptrdiff_t sstride;
int h;
int c;
int d;
int x;
int y;

static uint8_t *dst_buf;
static uint8_t *src_buf;

void init_vars() {
    h = 4096;
    c = 5;
    d = 3;
    dstride = 4096;
    sstride = 4096;

    size_t src_size = (h + 1) * sstride * sizeof(uint8_t);
    size_t dst_size = h * dstride * sizeof(uint8_t);

    src_buf = aligned_alloc(32, src_size);
    dst_buf = aligned_alloc(32, dst_size);

    if (!src_buf || !dst_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buf[i] = rand() % 256;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buf[i] = 0;
    }

    src = src_buf;
    dst = dst_buf;
}