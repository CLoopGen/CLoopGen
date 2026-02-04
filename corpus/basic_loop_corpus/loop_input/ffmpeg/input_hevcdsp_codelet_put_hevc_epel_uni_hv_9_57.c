#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 512;
int width = 1024;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride = 1024 * sizeof(uint16_t);
int8_t *filter;
int16_t *tmp;

void init_vars() {
    src = aligned_alloc(64, (height + 3) * srcstride);
    filter = aligned_alloc(64, 4 * sizeof(int8_t));
    tmp = aligned_alloc(64, width * sizeof(int16_t) * 64); // Enough for multiple rows

    for (int i = 0; i < 4; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    for (int i = 0; i < (height + 3) * width; i++) {
        src[i] = (uint16_t)(i % 256);
    }
}