#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int32_t dst_stride;
uint8_t i;

static uint8_t *dst_buffer;
static ptrdiff_t total_size = 1 << 20; // 1MB data size

void init_vars() {
    dst_stride = 32;
    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);
    if (!dst_buffer) exit(1);
    dst = dst_buffer;
}