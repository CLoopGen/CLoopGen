#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int srcWidth;
int x;

void init_vars() {
    srcWidth = 64 * 1024 * 1024; // 64 million elements to target ~0.01s runtime

    src = (uint8_t *)aligned_alloc(32, srcWidth * sizeof(uint8_t));
    dst = (uint8_t *)aligned_alloc(32, (2 * srcWidth + 2) * sizeof(uint8_t)); // Safe size for writes up to 2*x+2

    if (!src || !dst) {
        exit(1);
    }

    for (int i = 0; i < srcWidth; i++) {
        src[i] = (uint8_t)(i & 0xFF);
    }

    for (int i = 0; i < 2 * srcWidth + 2; i++) {
        dst[i] = 0;
    }

    x = 0;
}