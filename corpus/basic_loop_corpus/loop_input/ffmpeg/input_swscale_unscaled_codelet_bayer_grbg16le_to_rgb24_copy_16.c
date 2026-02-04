#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t))
#define WIDTH_FACTOR 2

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int w = TOTAL_ELEMENTS / WIDTH_FACTOR;
    const int h = 2;

    src_stride = w * 2;
    dst_stride = w * 3;

    width = w;

    src_buffer = aligned_alloc(32, (size_t)src_stride * (size_t)h);
    dst_buffer = aligned_alloc(32, (size_t)dst_stride * (size_t)h);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < src_stride * h; ++idx) {
        src_buffer[idx] = rand() & 0xFF;
    }
    for (int idx = 0; idx < dst_stride * h; ++idx) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}