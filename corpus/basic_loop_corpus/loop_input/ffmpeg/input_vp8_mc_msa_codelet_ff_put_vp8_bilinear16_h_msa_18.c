#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec runtime estimate

uint8_t *dst;
ptrdiff_t dst_stride = 16;
uint8_t *src;
ptrdiff_t src_stride = 16;
uint32_t loop_cnt;

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];

void init_vars() {
    if (!dst) {
        dst = internal_dst;
    }
    if (!src) {
        src = internal_src;
    }
    loop_cnt = DATA_SIZE / (4 * dst_stride);
}