#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int32_t dst_stride;
int32_t height;
uint8_t *dst_ptr;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    const int32_t block_height = 1 << 14; // ~16k blocks of 4 rows -> large enough for ~0.01s
    const int32_t block_width_bytes = 64; // 64 bytes per row (e.g., 64 pixels)

    height = block_height;
    src_stride = block_width_bytes;
    dst_stride = block_width_bytes;

    total_src_size = (size_t)(height + 4) * (size_t)src_stride; // extra space to prevent overflow
    total_dst_size = (size_t)(height + 4) * 2 * (size_t)dst_stride;

    src_buffer = aligned_alloc(32, total_src_size);
    dst_buffer = aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst_ptr = dst_buffer;

    cnt = 0;
}