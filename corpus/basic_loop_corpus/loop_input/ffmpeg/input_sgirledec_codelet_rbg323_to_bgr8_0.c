#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int size;
int i;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on typical modern CPU

    src = (uint8_t *)aligned_alloc(32, size * sizeof(uint8_t));
    dst = (uint8_t *)aligned_alloc(32, size * sizeof(uint8_t));

    if (!src || !dst) {
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }
}