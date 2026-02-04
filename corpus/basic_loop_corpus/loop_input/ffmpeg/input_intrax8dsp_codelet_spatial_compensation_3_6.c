#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t src_size = 256 * (1 << 20); // 256 MB for src
    size_t dst_size = 256 * (1 << 20); // 256 MB for dst
    stride = 8; // Each row advances by 8 bytes

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer + (8 + 8 + 1); // Base offset to prevent out-of-bounds in first access
    dst = dst_buffer;
}