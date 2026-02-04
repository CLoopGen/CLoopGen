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
uint32_t dcsplat;

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB to target ~0.01 sec runtime
static uint8_t global_src_data[DATA_SIZE];

void init_vars() {
    stride = 16;  // Each row advances by 16 bytes (4x uint32_t)
    src = global_src_data;
    dcsplat = 0xDEADBEEF;
}

// Ensure the loop runs exactly 16 times without out-of-bounds access
// Total memory accessed: 16 iterations * stride (16) = 256 bytes per column
// We have 64MB allocated, so we are well within bounds