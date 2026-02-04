#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
uint8_t *dst;
uint8_t *f1;
uint8_t *f2;
int w;

void init_vars() {
    w = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec runtime on modern CPU

    src = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));
    dst = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));
    f1 = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));
    f2 = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));

    if (!src || !dst || !f1 || !f2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < w; i++) {
        src[i] = (uint8_t)(rand() % 256);
        f1[i] = (uint8_t)(rand() % 256);
        f2[i] = (uint8_t)(rand() % 256);
        dst[i] = 0;
    }
}