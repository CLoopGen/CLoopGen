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

ptrdiff_t stride = 16;
int i;
uint32_t a = 0xDEADBEEF;
uint8_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB
    src = aligned_alloc(32, data_size);
    if (!src) {
        exit(1);
    }
    a = 0xCAFEBABE;
    stride = 16;
    for (int i = 0; i < 8; i++) {
        uint8_t *row = src + i * stride;
        ((uint32_t*)row)[0] = 0;
        ((uint32_t*)row)[1] = 0;
    }
}