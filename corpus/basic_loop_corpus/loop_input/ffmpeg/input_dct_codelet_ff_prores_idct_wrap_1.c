#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int i;

void init_vars() {
    size_t data_size = 131072; // 256KB of data (131072 * 2 bytes) to target ~0.01 sec runtime
    dst = (int16_t *)aligned_alloc(_Alignof(int16_t), data_size * sizeof(int16_t));
    if (!dst) exit(1);
    for (size_t j = 0; j < data_size; j++) {
        dst[j] = 1024;
    }
}