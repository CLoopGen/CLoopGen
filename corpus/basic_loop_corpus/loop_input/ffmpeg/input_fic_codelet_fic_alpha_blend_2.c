#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int size;
uint8_t *alpha;
int i;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    dst = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));
    src = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));
    alpha = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));

    if (!dst || !src || !alpha) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        dst[j] = rand() % 256;
        src[j] = rand() % 256;
        alpha[j] = rand() % 256;
    }
}