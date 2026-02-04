#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *pixels;
int w = 131072; // 256KB of data: 131072 elements * 2 bytes = 256KB
int color = 0xABCD;
int i;

void init_vars() {
    pixels = (uint16_t*)aligned_alloc(_Alignof(uint16_t), w * sizeof(uint16_t));
    if (!pixels) {
        exit(1);
    }
}