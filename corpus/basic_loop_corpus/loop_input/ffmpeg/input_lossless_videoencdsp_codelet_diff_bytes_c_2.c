#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
intptr_t w;
long i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    dst = aligned_alloc(32, data_size);
    src1 = aligned_alloc(32, data_size);
    src2 = aligned_alloc(32, data_size);

    for (size_t j = 0; j < data_size; ++j) {
        src1[j] = rand() % 256;
        src2[j] = rand() % 256;
    }

    w = data_size - 7; // Ensure i+7 < w is safe and last iteration doesn't overflow
}