#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
int i;
uint16_t *src;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB
static uint16_t data_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 16; // Ensure forward progress and alignment
    src = data_buffer;
}

// Note: The loop function is defined externally and will be linked in.