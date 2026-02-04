#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int width;
int i;

void init_vars() {
    width = 10 * 1024 * 1024; // ~20 MB of int16_t data (10M elements)
    dst = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    if (!dst) {
        exit(1);
    }
    for (int j = 0; j < width; j++) {
        dst[j] = rand() % 65536 - 32768; // Random int16_t values
    }
}