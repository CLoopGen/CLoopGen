#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // 64 MB of data
    src_stride = 4096; // Typical cache-line aligned stride
    height = (total_size / src_stride) & ~7; // Ensure height is multiple of 8

    src_buffer = (uint8_t*)aligned_alloc(64, total_size);
    if (!src_buffer) {
        exit(1);
    }

    src = src_buffer;
}