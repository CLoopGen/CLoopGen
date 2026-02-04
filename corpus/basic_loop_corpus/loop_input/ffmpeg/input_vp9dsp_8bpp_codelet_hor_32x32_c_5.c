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
uint8_t *dst;
uint8_t *left;
int y;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *dst_buffer;
static uint8_t *left_buffer;

void init_vars() {
    // Allocate buffers
    dst_buffer = aligned_alloc(32, DATA_SIZE);
    left_buffer = aligned_alloc(32, 32);

    // Initialize buffers to avoid undefined behavior
    for (size_t i = 0; i < DATA_SIZE; i++) {
        dst_buffer[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 32; i++) {
        left_buffer[i] = (uint8_t)(i + 1);
    }

    // Initialize external pointers and variables
    dst = dst_buffer;
    left = left_buffer;
    stride = 32; // Ensure each row advances by 32 bytes
}