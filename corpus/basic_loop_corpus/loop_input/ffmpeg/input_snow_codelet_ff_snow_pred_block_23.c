#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t stride;
int b_w;
int b_h;
int x;
int y;
unsigned int color;

void init_vars() {
    b_w = 4096;
    b_h = 4096;
    stride = b_w;
    color = 0xFF;

    dst = aligned_alloc(32, (size_t)b_h * (size_t)stride);
    if (!dst) {
        exit(1);
    }
}