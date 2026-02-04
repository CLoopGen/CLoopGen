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
uint32_t a;
uint32_t b;

void init_vars() {
    a = 0xdeadbeef;
    b = 0xc0decafe;
    stride = 8;
    size_t total_size = 8 * stride;
    src = aligned_alloc(32, total_size);
    if (!src) {
        exit(1);
    }
    for (size_t idx = 0; idx < total_size; idx++) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }
}