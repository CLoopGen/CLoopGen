#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1 << 20;
int my = 15;
int avg = 1;
uint8_t *tmp_ptr;
uint8_t *dst;
int x;

void init_vars() {
    tmp_ptr = aligned_alloc(64, (w + 64) * sizeof(uint8_t));
    dst = aligned_alloc(64, w * sizeof(uint8_t));

    for (int i = 0; i < w; i++) {
        dst[i] = i % 256;
        tmp_ptr[i] = (i * 7) % 256;
    }
    for (int i = w; i < w + 64; i++) {
        tmp_ptr[i] = (i * 13) % 256;
    }
}