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
static size_t total_size = 1 << 20; // 1MB for ~0.01s runtime estimate

void init_vars() {
    src_buffer = (uint8_t *)calloc(total_size, sizeof(uint8_t));
    dst_buffer = (uint8_t *)calloc(total_size, sizeof(uint8_t));
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer + 16; // Ensure offset access (8+8) is valid
    dst = dst_buffer;
    stride = 8; // Advance dst by 8 bytes per row

    // Initialize src with non-zero data to make transformations observable
    for (size_t i = 0; i < total_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
}