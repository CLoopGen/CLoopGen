#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint32_t row;

static uint8_t *dst_buffer;
static size_t total_size = 16 << 20; // 16 MB to target ~0.01 sec runtime

void init_vars() {
    dst_stride = 512;
    dst_buffer = aligned_alloc(64, total_size);
    if (!dst_buffer) exit(1);
    dst = dst_buffer;
}