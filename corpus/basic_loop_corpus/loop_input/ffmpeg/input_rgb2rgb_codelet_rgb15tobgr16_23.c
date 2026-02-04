#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int i;
int num_pixels;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    num_pixels = data_size / sizeof(uint16_t);

    uint16_t *src_aligned = aligned_alloc(16, data_size);
    uint16_t *dst_aligned = aligned_alloc(16, data_size);

    for (int j = 0; j < num_pixels; j++) {
        src_aligned[j] = rand() & 0xFFFF;
    }

    src = (uint8_t *)src_aligned;
    dst = (uint8_t *)dst_aligned;
}