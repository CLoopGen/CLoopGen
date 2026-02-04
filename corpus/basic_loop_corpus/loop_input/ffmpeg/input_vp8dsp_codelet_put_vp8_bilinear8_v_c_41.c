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

static uint8_t *dst_data;
static uint8_t *src_data;

void init_vars() {
    const int width = 8;
    h = 16384;  // Adjusted for ~0.01s runtime (empirically reasonable for modern CPU)
    c = 5;
    d = 3;

    dstride = width;
    sstride = width;

    size_t dst_size = (size_t)h * dstride;
    size_t src_size = (size_t)(h + 1) * sstride;  // +1 to allow src[x + sstride] at last row

    dst_data = aligned_alloc(32, dst_size);
    src_data = aligned_alloc(32, src_size);

    if (!dst_data || !src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < dst_size; i++) {
        dst_data[i] = rand() % 256;
    }
    for (size_t i = 0; i < src_size; i++) {
        src_data[i] = rand() % 256;
    }

    dst = dst_data;
    src = src_data;
}