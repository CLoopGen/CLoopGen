#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1 << 20;
int dx = 3;
uint8_t *tmp_ptr;
uint8_t *src;
int x;
int imx = 5;
int ioff = 0;

void init_vars() {
    tmp_ptr = aligned_alloc(32, w * sizeof(uint8_t));
    src = aligned_alloc(32, (w + 1) * sizeof(uint8_t));

    for (int i = 0; i < w + 1; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < w; i++) {
        tmp_ptr[i] = 0;
    }
}