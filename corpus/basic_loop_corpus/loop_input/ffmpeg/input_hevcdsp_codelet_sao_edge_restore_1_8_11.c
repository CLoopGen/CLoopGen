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

static uint8_t memory_pool_src[TOTAL_BYTES];
static uint8_t memory_pool_dst[TOTAL_BYTES];

void init_vars() {
    width = 1920;
    height = 1080;
    stride_src = width + 64;
    stride_dst = width + 64;
    init_y = 0;
    save_upper_right = 1;
    save_lower_right = 1;

    src = memory_pool_src;
    dst = memory_pool_dst;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            src[i * stride_src + j] = rand() % 256;
        }
    }
}