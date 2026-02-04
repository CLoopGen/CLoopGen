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
uint32_t dc0splat;
uint32_t dc1splat;
uint8_t *src;

void init_vars() {
    stride = 16;
    dc0splat = 0x12345678;
    dc1splat = 0xABCDEF01;
    
    size_t total_size = 256 * 1024 * 1024; // 256 MB
    src = (uint8_t*)aligned_alloc(32, total_size);
    if (!src) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_size; idx++) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }
}