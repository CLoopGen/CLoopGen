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

int i;
uint8_t *src;
int stride;
uint32_t a = 0xdeadbeef;
uint32_t b = 0xcafebabe;
uint32_t c = 0xabad1dea;
uint32_t d = 0x12345678;

static uint8_t *internal_src_buffer;
static int internal_stride;

void init_vars() {
    internal_stride = 64; // Aligned row size
    size_t total_size = 256 * 1024 * 1024; // 256 MB to ensure ~0.01s runtime
    internal_src_buffer = (uint8_t *)aligned_alloc(32, total_size);
    if (!internal_src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize the buffer to zero
    for (size_t i = 0; i < total_size; i++) {
        internal_src_buffer[i] = 0;
    }

    // Set extern variables
    src = internal_src_buffer;
    stride = internal_stride;
}