#include <stdint.h>
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
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    const int element_size = 1;
    height = data_size / element_size;
    stride_dst = 1;
    stride_src = 1;

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
}