#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int height;
ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime estimate

    dst_buffer = aligned_alloc(32, data_size);
    src_buffer = aligned_alloc(32, data_size);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    dst = dst_buffer;
    src = src_buffer;
    height = (int)(data_size / sizeof(uint16_t));
    stride_dst = sizeof(uint16_t);
    stride_src = sizeof(uint16_t);
}