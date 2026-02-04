#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
ptrdiff_t stride;
int dirr;
int dirg;
int dirb;
int dots[16];
int stops[4];
int x;
int y;
int k;
uint8_t color[16];

void init_vars() {
    dirr = 1;
    dirg = 2;
    dirb = 3;
    k = 0;

    for (int i = 0; i < 16; i++) {
        color[i] = (uint8_t)(i * 5);
    }

    stride = 16;
    size_t total_size = 16 * 1024 * 1024; // ~16MB to ensure sufficient runtime (~0.01 sec on modern CPU)
    block = (uint8_t*)aligned_alloc(32, total_size);
    if (!block) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        block[i] = (uint8_t)((i * 7) % 256);
    }
}