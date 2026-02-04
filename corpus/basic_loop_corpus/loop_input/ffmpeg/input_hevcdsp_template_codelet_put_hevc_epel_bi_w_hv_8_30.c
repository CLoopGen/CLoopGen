#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 64;
int width = 64;
int x;
int y;
uint8_t *src;
ptrdiff_t srcstride = 64;
int8_t *filter;
int16_t *tmp;

void init_vars() {
    src = aligned_alloc(64, (height + 3) * srcstride);
    tmp = aligned_alloc(64, (height + 3) * 64 * sizeof(int16_t));
    filter = aligned_alloc(64, 4 * sizeof(int8_t));

    for (int i = 0; i < 4; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    for (int i = 0; i < (height + 3) * srcstride; i++) {
        src[i] = (uint8_t)(i % 256);
    }
}