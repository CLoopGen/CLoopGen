#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int left;
int i;
int min_width;

void init_vars() {
    min_width = 134217728; // ~128MB of data to target ~0.01 sec runtime on modern CPU

    src = (uint8_t*)aligned_alloc(32, min_width * sizeof(uint8_t));
    dst = (uint8_t*)aligned_alloc(32, min_width * sizeof(uint8_t));

    if (!src || !dst) {
        exit(1);
    }

    for (int idx = 0; idx < min_width; idx++) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }

    left = 42;
}