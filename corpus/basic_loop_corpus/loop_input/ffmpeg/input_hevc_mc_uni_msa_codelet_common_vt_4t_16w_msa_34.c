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

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // 64 MB of data to ensure ~0.01 sec runtime
    src_stride = 2048;
    dst_stride = 2048;
    height = (total_size / src_stride) & ~3; // Ensure height is multiple of 4

    if ((src_buffer = aligned_alloc(32, total_size)) == NULL) abort();
    if ((dst_buffer = aligned_alloc(32, total_size)) == NULL) abort();

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 255);
    }
}