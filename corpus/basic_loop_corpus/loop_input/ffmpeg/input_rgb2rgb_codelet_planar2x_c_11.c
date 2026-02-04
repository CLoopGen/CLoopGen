#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int srcWidth;
int x;

void init_vars() {
    srcWidth = 64 * 1024 * 1024; // 64 million elements to target ~0.01 sec runtime

    src = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * (srcWidth));
    dst = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * (2 * srcWidth + 2));

    for (int i = 0; i < srcWidth; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 2 * srcWidth + 2; i++) {
        dst[i] = 0;
    }

    x = 0;
}