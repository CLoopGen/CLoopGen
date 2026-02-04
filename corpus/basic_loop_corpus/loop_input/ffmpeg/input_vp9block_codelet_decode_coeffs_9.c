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
    a = (uint8_t *)aligned_alloc(32, data_size);
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize array with non-zero values to make computation meaningful
    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (uint8_t)(i % 251); // Prime number to avoid patterns
    }

    // Set loop bounds to ensure no out-of-bounds access:
    // We write u32 at a[n] and a[n+4], so we need n+7 < data_size
    // Since n goes up by 2 each time, set end_x to maximum even index satisfying this
    end_x = ((data_size - 8) / 2) * 2;
    if (end_x <= 0) {
        end_x = 0;
    }
}

// Ensure symbols are defined
int end_x;
int n;
uint8_t *a;