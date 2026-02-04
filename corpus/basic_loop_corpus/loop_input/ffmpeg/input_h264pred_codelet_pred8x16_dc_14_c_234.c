#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
int i;
uint64_t dc4splat;
uint64_t dc5splat;
uint16_t *src;

void init_vars() {
    dc4splat = 0x0F0F0F0F0F0F0F0FULL;
    dc5splat = 0xF0F0F0F0F0F0F0F0ULL;

    size_t total_size = 256 * 1024 * 1024; // 256 MB
    size_t num_elements = total_size / sizeof(uint16_t);
    src = (uint16_t *)aligned_alloc(64, total_size);
    if (!src) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    stride = 16; 
}

__attribute__((destructor)) void cleanup() {
    free(src);
}