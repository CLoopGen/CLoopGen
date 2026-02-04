#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src;
unsigned int mask;
int w;
long i;

void init_vars() {
    w = 67108864; // 128 MB of data (67M elements * 2 bytes * 2 arrays ≈ 256 MB total)
    dst = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));
    src = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));
    if (!dst || !src) {
        exit(1);
    }
    for (int j = 0; j < w; j++) {
        dst[j] = (uint16_t)(j & 0xFFFF);
        src[j] = (uint16_t)((j + 100) & 0xFFFF);
    }
    mask = 0x7FFF; // Example mask to keep lower 15 bits
    i = 0;
}