#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1048576; // ~1M elements to target ~0.01 sec runtime
int my = 15;
int avg = 1;

uint16_t *tmp_ptr;
uint16_t *dst;
int x;

void init_vars() {
    tmp_ptr = (uint16_t*)aligned_alloc(32, (w + 64) * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));

    for (int i = 0; i < w; i++) {
        dst[i] = (uint16_t)(i % 30000);
        tmp_ptr[i] = (uint16_t)((i * 3) % 30000);
    }

    for (int i = w; i < w + 64; i++) {
        tmp_ptr[i] = (uint16_t)((i * 7) % 30000);
    }
}