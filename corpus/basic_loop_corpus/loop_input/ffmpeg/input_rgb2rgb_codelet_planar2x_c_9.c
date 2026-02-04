#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int srcWidth;
int x;

void init_vars() {
    srcWidth = 64 * 1024 * 1024; // 64 million elements to ensure ~0.01s runtime
    src = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * (srcWidth + 1));
    dst = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * (2 * srcWidth + 2));

    if (!src || !dst) {
        exit(1);
    }

    for (int i = 0; i < srcWidth + 1; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 2 * srcWidth + 2; i++) {
        dst[i] = 0;
    }
}