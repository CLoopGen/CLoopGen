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

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB to target ~0.01 sec runtime
static uint8_t src_buffer[DATA_SIZE];

void init_vars() {
    stride = 16;  // Ensures that i*stride < DATA_SIZE for i in [0,15]
    src = src_buffer + 1;  // Point to offset 1 to allow access to src[-1] safely
    for (int j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = (uint8_t)(j & 0xFF);
    }
}