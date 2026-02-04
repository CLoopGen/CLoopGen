#include <stdint.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint32_t row;

static uint8_t buffer[1 << 20]; // 1MB buffer to ensure sufficient data size

void init_vars() {
    dst_stride = 64;
    dst = buffer;
}