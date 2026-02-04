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
uint32_t dc;
int y;

#define DATA_SIZE (64 * 1024 * 1024) // 64MB to ensure ~0.01s runtime
static uint8_t buffer[DATA_SIZE];

void init_vars() {
    stride = 16; // Each row advances by 16 bytes (4x uint32)
    dst = buffer;
    dc = 0xdeadbeef; // Arbitrary value for dc
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}