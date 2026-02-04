#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride = 1024 * sizeof(uint16_t);
int8_t *filter;
int16_t *tmp;

void init_vars() {
    src = aligned_alloc(32, (height + 3) * srcstride);
    filter = aligned_alloc(32, 4 * sizeof(int8_t));
    tmp = aligned_alloc(32, width * sizeof(int16_t) * (height + 3));

    for (int i = 0; i < (height + 3) * (width); i++) {
        src[i] = rand() & 0xFFFF;
    }

    filter[0] = 15;
    filter[1] = 73;
    filter[2] = 73;
    filter[3] = 15;

    for (int i = 0; i < width * (height + 3); i++) {
        tmp[i] = 0;
    }
}