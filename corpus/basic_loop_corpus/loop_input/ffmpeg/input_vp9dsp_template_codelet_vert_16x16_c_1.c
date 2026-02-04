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
size_t total_data_size = 16 * 256 * 1024; // 4MB total (ensures ~0.01s runtime)

void init_vars() {
    p4a = 0x11223344U;
    p4b = 0x55667788U;
    p4c = 0x99AABBCCU;
    p4d = 0xDDEEFF00U;
    stride = 16;

    base_dst = (uint8_t*)aligned_alloc(32, total_data_size);
    if (!base_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    dst = base_dst;
}