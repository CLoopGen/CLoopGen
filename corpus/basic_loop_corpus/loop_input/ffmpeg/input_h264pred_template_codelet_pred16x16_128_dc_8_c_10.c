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
uint8_t *src;

uint8_t *src_base;
size_t data_size = 1 << 20; // 1MB

void init_vars() {
    stride = 16;
    src_base = (uint8_t*)aligned_alloc(32, data_size);
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    src = src_base;
}

__attribute__((destructor)) void cleanup() {
    free(src_base);
}