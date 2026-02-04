#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
int i;
uint8_t *src;

static uint8_t *src_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    src_buffer = aligned_alloc(32, data_size);
    if (!src_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_buffer[idx] = rand() & 0xFF;
    }

    stride = 64; // Ensure sufficient spacing to prevent out-of-bounds access
    src = src_buffer + 1; // Offset by 1 so that src[-1] is valid at the first iteration
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
}