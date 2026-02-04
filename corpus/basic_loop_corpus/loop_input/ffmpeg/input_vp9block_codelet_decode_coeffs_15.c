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
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    a = (uint8_t*)aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }

    // Initialize array with non-zero and zero values to ensure meaningful behavior
    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (i % 7 == 0) ? 0 : (uint8_t)(i * 5 + 17);
    }

    // Ensure that the loop does not exceed bounds: n < end_x, and we access up to a[n+3]
    // So end_x must be <= data_size - 3, and multiple of 4 is not required but safe
    end_x = data_size - (data_size % 4) - 4; // Largest multiple of 4 less than data_size-3
    if (end_x < 0) end_x = 0;
}