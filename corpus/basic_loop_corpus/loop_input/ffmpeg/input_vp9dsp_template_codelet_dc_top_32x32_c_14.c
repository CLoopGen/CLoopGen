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

ptrdiff_t stride = 32;
uint8_t *dst;
uint32_t dc = 0xdeadbeef;
int y;

uint8_t *dst_buffer;

void init_vars() {
    const size_t buffer_size = 1 << 20; // 1MB
    dst_buffer = aligned_alloc(32, buffer_size);
    if (!dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    dst = dst_buffer;
    dc = 0xdeadbeef;
    stride = 32;
    y = 0;
}