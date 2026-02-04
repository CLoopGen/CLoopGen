#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
int size;
int alpha;
int i;

void init_vars() {
    size = 64 * 1024 * 1024; // 128MB of data (64M elements of uint16_t)
    dst = (uint16_t*)aligned_alloc(32, size * sizeof(uint16_t));
    if (!dst) exit(1);

    for (int j = 0; j < size; ++j) {
        dst[j] = (uint16_t)(j % 30000);
    }

    alpha = 1;
}