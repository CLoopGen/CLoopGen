#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int src_size;
unsigned int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    src = (uint8_t*)aligned_alloc(32, data_size);
    dst = (uint8_t*)aligned_alloc(32, data_size);

    if (!src || !dst) {
        exit(1);
    }

    src_size = (data_size / 3) * 3; // Ensure divisible by 3 to avoid out-of-bounds access

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }
}