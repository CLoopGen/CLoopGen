#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int threshold = 10;
int w = 131072; // 131072 elements * sizeof(uint16_t) = 262144 bytes (~0.25MB), sufficient for ~0.01 sec runtime

uint16_t *src;
uint16_t *ref;
uint16_t *dst;

void init_vars() {
    src = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));
    ref = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));

    for (int i = 0; i < w; i++) {
        src[i] = (uint16_t)(rand() % 1000);
        ref[i] = (uint16_t)(rand() % 1000);
    }
}