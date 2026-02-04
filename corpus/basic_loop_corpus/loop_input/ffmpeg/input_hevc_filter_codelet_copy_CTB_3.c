#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

uint8_t *dst;
uint8_t *src;
int width;
int height;
ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int i;
int j;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size;

void init_vars() {
    width = 1920;
    height = 1080;
    stride_dst = 1920;
    stride_src = 1920;
    total_size = (size_t)width * height;

    src_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t k = 0; k < total_size; k++) {
        src_buffer[k] = (uint8_t)(k % 256);
    }
    memset(dst_buffer, 0, total_size);

    src = src_buffer;
    dst = dst_buffer;

    i = 0;
    j = 0;
}