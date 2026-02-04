#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int w;
int i;
int r;
int g;
int b;

void init_vars() {
    const size_t data_size = 16777216; // ~16MB to ensure loop runtime around 0.01s
    src = (uint8_t*)aligned_alloc(32, data_size);
    dst = (uint8_t*)aligned_alloc(32, data_size);

    if (!src || !dst) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        src[idx] = rand() % 256;
    }

    w = (data_size / 3) > 16 ? 16 : (data_size / 3); // Ensure w <= 16 or valid size
    r = src[0];
    g = src[1];
    b = src[2];
}