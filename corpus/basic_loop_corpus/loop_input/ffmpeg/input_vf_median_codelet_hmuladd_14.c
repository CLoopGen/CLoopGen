#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src;
int f;
int bins;

void init_vars() {
    bins = 67108864; // 128MB of data: 67M elements * 2 bytes per uint16_t ≈ 128MB
    f = 3;

    dst = (uint16_t*)aligned_alloc(32, bins * sizeof(uint16_t));
    src = (uint16_t*)aligned_alloc(32, bins * sizeof(uint16_t));

    for (int i = 0; i < bins; i++) {
        dst[i] = i & 0x3FF;
        src[i] = (i + 123) & 0x3FF;
    }
}