#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    const size_t data_size = 64 << 20; // 64 MB of data to ensure ~0.01s runtime
    src_stride = 2048;
    dst_stride = 2048;
    height = (data_size / src_stride) & ~1; // Ensure divisible by 2 for loop shift

    total_src_size = (height / 2) * src_stride + 2 * src_stride;
    total_dst_size = (height / 2) * dst_stride + 2 * dst_stride;

    src_buffer = aligned_alloc(32, total_src_size);
    dst_buffer = aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer + src_stride;
    dst = dst_buffer + dst_stride;

    loop_cnt = 0;
}