#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *d;
ptrdiff_t stride;
int x;
int y;
int ia;
int ih;
int iv;
uint8_t *cm;

void init_vars() {
    const int width = 8;
    const int height = 8;
    stride = 16;

    d = aligned_alloc(32, stride * height);
    cm = aligned_alloc(32, 256);

    ia = 16;
    ih = 1;
    iv = 4;

    for (int i = 0; i < 256; ++i) {
        cm[i] = (uint8_t)(i * i + 3 * i + 1) & 0xFF;
    }

    for (int i = 0; i < stride * height; ++i) {
        d[i] = 0;
    }
}