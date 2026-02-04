#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint32_t row;

static uint8_t *dst_buffer;

void init_vars() {
    dst_stride = 65536;
    dst_buffer = (uint8_t *)aligned_alloc(32, dst_stride * 16);
    if (!dst_buffer) {
        exit(1);
    }
    dst = dst_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
}