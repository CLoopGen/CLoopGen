#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride = 1024;
int8_t *filter;
int16_t *tmp;

void init_vars() {
    src = aligned_alloc(64, sizeof(uint16_t) * (height + 3) * srcstride);
    tmp = aligned_alloc(64, sizeof(int16_t) * width * 64);
    filter = aligned_alloc(64, sizeof(int8_t) * 4);

    for (int i = 0; i < 4; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    for (int i = 0; i < (height + 3) * srcstride; i++) {
        src[i] = (uint16_t)(i % 256);
    }
}