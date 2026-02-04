#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int block_height = 2;
    const int pixel_size = 3;
    const int element_size = 1;
    const int src_element_step = 1;
    const int dst_element_step = 3;

    width = 1 << 16;

    src_stride = 2 * width;
    dst_stride = 3 * width;

    size_t src_size = (size_t)block_height * src_stride * element_size;
    size_t dst_size = (size_t)block_height * dst_stride * pixel_size;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < dst_size; ++idx) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}