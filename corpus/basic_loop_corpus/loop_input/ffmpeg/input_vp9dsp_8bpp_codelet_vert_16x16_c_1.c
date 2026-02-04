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
uint32_t p4a;
uint32_t p4b;
uint32_t p4c;
uint32_t p4d;
int y;

uint8_t *base_dst;

void init_vars() {
    p4a = 0x12345678U;
    p4b = 0xABCDEF01U;
    p4c = 0x5A5A5A5AU;
    p4d = 0x9B9B9B9BU;

    stride = 16;

    base_dst = aligned_alloc(32, 16 * 16);
    if (!base_dst) {
        exit(1);
    }
    dst = base_dst;
}