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
uint16_t *dst;
uint64_t dc;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of data
static uint16_t buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 32; // ensures 8 writes of 8 bytes each per row fit within stride
    dst = buffer;
    dc = 0x0123456789ABCDEFULL;
    y = 0;
}