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

uint8_t *dst_base;
size_t data_size = 1 << 20; // 1MB of data

void init_vars() {
    stride = 16;
    dc = 0xdeadbeef;
    dst_base = aligned_alloc(32, data_size);
    if (!dst_base) {
        exit(1);
    }
    dst = dst_base;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_base);
}