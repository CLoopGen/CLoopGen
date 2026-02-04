#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int width;
int i;

void init_vars() {
    width = 1048576; // Approximately 2MB of int16_t data (1<<20 elements)
    dst = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    if (!dst) {
        exit(1);
    }
    for (int j = 0; j < width; j++) {
        dst[j] = (int16_t)(j & 0xFFFF);
    }
}