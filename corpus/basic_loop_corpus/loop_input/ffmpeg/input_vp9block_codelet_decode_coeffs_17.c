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

int end_x;
int n;
uint8_t *a;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    a = (uint8_t*)aligned_alloc(16, data_size);
    if (!a) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (uint8_t)(i & 0xFF);
    }
    end_x = (int)(data_size - 4); // Ensure n+4 does not exceed bounds
}