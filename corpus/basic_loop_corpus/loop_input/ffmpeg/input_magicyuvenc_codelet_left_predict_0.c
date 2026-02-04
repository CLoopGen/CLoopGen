#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int width;
uint8_t prev;
int i;

void init_vars() {
    width = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    src = (uint8_t*)aligned_alloc(32, width * sizeof(uint8_t));
    dst = (uint8_t*)aligned_alloc(32, width * sizeof(uint8_t));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < width; j++) {
        src[j] = rand() & 0xFF;
    }
    prev = rand() & 0xFF;
}