#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src;
int bins;

void init_vars() {
    bins = 67108864; // 128 MB of data (67,108,864 elements * 2 bytes each ~ 128 MB)
    dst = (uint16_t*)aligned_alloc(32, bins * sizeof(uint16_t));
    src = (uint16_t*)aligned_alloc(32, bins * sizeof(uint16_t));

    for (int i = 0; i < bins; i++) {
        dst[i] = i & 0xFFFF;
        src[i] = (i + 100) & 0xFFFF;
    }
}