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

uint16_t *src_base;
size_t data_size;
ptrdiff_t stride_default = 16;

void init_vars() {
    data_size = 1024 * 1024; // 1MB of data
    src_base = (uint16_t *)aligned_alloc(8, data_size);
    if (!src_base) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); ++idx) {
        src_base[idx] = 0;
    }
    src = src_base;
    stride = stride_default;
    i = 0;
}