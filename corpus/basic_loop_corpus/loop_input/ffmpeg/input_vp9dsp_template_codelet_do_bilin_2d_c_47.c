#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 16777216; // ~16M elements to target ~0.01s runtime
int my = 32;
int avg = 1;

uint8_t *tmp_ptr;
uint8_t *dst;
int x;

void init_vars() {
    tmp_ptr = aligned_alloc(32, w + 64);
    dst = aligned_alloc(32, w);

    for (int i = 0; i < w; i++) {
        dst[i] = (uint8_t)(i & 0xFF);
        tmp_ptr[i] = (uint8_t)((i * 3) & 0xFF);
    }
    for (int i = w; i < w + 64; i++) {
        tmp_ptr[i] = (uint8_t)((i * 7) & 0xFF);
    }
}