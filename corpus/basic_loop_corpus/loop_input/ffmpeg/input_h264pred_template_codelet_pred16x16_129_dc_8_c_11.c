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

ptrdiff_t stride = 16;
int i;
uint8_t *src;

static uint8_t *src_buffer;

void init_vars() {
    const size_t data_size = 16 * 16 * 1024; // 256KB to target ~0.01s runtime
    src_buffer = aligned_alloc(32, data_size);
    if (!src_buffer) {
        exit(1);
    }
    src = src_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
}