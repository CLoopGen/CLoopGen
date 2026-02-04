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

ptrdiff_t stride = 64;
uint8_t *dst;
uint8_t *left;
int y;

uint8_t *dst_base;
uint8_t *left_base;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB
    dst_base = aligned_alloc(64, data_size);
    left_base = aligned_alloc(64, 32);

    if (!dst_base || !left_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = dst_base;
    left = left_base;

    for (int i = 0; i < 32; i++) {
        left[i] = (uint8_t)(i * 7 + 3); 
    }

    for (size_t i = 0; i < data_size; i++) {
        dst_base[i] = 0;
    }
}