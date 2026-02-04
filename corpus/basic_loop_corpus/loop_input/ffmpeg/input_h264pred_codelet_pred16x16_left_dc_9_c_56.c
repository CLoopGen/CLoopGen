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
uint16_t *src;
uint64_t dcsplat;

uint16_t *src_base;
size_t data_size;
ptrdiff_t stride_in_elements;

void init_vars() {
    data_size = 16777216; // 16 MB of uint16_t data
    src_base = (uint16_t*)aligned_alloc(64, data_size * sizeof(uint16_t));
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        src_base[idx] = (uint16_t)(idx & 0xFFFF);
    }

    dcsplat = 0x0F0F0F0F0F0F0F0FULL;
    stride_in_elements = 16;
    stride = stride_in_elements;

    src = src_base;
}

__attribute__((destructor))
void cleanup() {
    free(src_base);
}