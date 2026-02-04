#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int y;
uint8_t *dst;
uint8_t *src;
int init_y;
int width;
int height;
int save_upper_right;
int save_lower_right;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024ULL)

static uint8_t *buffer_dst;
static uint8_t *buffer_src;

void init_vars() {
    width = 4096;
    height = (TOTAL_BYTES / sizeof(uint8_t)) / width;
    if (height < 2) height = 2;
    stride_dst = width;
    stride_src = width;

    init_y = 0;
    save_upper_right = 0;
    save_lower_right = 1;

    buffer_dst = aligned_alloc(32, (size_t)(height * stride_dst));
    buffer_src = aligned_alloc(32, (size_t)(height * stride_src));

    dst = buffer_dst;
    src = buffer_src;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            buffer_src[i * stride_src + j] = (uint8_t)((i + j) & 0xFF);
        }
    }
}