#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src_ptr;
int32_t src_stride;
uint8_t *ref_ptr;
int32_t ref_stride;
int32_t height;
int32_t ht_cnt;

static uint8_t *src_buffer;
static uint8_t *ref_buffer;

void init_vars() {
    // Allocate approximately 64MB for each buffer to ensure meaningful runtime (~0.01 sec)
    size_t total_size = (1 << 26); // 64 MB
    src_buffer = (uint8_t*)aligned_alloc(32, total_size);
    ref_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!src_buffer || !ref_buffer) {
        exit(1);
    }

    // Initialize with dummy data
    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        ref_buffer[i] = (uint8_t)((i + 123) & 0xFF);
    }

    // Set stride and height values
    src_stride = 2048;
    ref_stride = 2048;
    height = 8192;

    // Initialize pointers to middle of buffers to allow movement in loop
    ptrdiff_t offset = (src_stride * (height / 2)) & ~(ptrdiff_t)31;
    if (offset + (height * src_stride) > total_size) {
        offset = total_size - (height * src_stride) - 1;
    }

    src_ptr = src_buffer + offset;
    ref_ptr = ref_buffer + offset;
}