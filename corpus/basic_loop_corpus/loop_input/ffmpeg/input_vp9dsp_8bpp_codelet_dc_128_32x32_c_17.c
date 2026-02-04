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
uint32_t val;
int y;

uint8_t *dst_base;
ptrdiff_t total_size = 1 << 20; // 1MB

void init_vars() {
    stride = 32;
    val = 0xdeadbeef;
    dst_base = aligned_alloc(32, total_size);
    if (!dst_base) {
        exit(1);
    }
    dst = dst_base;
}

__attribute__((destructor)) void cleanup() {
    free(dst_base);
}