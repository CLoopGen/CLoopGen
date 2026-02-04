#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint32_t row;

static uint8_t *dst_buffer;
static ptrdiff_t effective_stride;

void init_vars() {
    effective_stride = 64;
    dst_stride = effective_stride;

    size_t total_size = 256 * 1024 * 1024;
    size_t buffer_rows = total_size / (2 * effective_stride);
    if (buffer_rows < 32) {
        buffer_rows = 32;
    }
    size_t alloc_size = buffer_rows * effective_stride;

    dst_buffer = aligned_alloc(64, alloc_size);
    if (!dst_buffer) {
        exit(1);
    }

    dst = dst_buffer;
}