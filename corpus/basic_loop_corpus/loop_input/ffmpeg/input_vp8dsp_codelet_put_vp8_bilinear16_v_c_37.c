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

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024ULL)

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t width = 16;
    h = (TOTAL_BYTES / 2) / (width * 2); 
    if (h == 0) h = 1;

    size_t src_size = (h + 1) * width; 
    size_t dst_size = h * width;

    dst_buffer = aligned_alloc(32, dst_size);
    src_buffer = aligned_alloc(32, src_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    dst = dst_buffer;
    src = src_buffer;
    dstride = width;
    sstride = width;
    c = 5;
    d = 3;
}