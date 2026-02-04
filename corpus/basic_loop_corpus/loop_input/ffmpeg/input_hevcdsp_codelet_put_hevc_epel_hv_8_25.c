#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;
uint8_t *src;
ptrdiff_t srcstride = 1024;
int8_t *filter;
int16_t *tmp;

void init_vars() {
    src = aligned_alloc(32, (height + 3) * srcstride * sizeof(uint8_t));
    tmp = aligned_alloc(32, (width + 3) * 64 * sizeof(int16_t));
    filter = aligned_alloc(32, 4 * sizeof(int8_t));

    for (int i = 0; i < (height + 3) * srcstride; i++) {
        src[i] = rand() % 256;
    }
    for (int i = 0; i < 4; i++) {
        filter[i] = (rand() % 256) - 128;
    }
    for (int i = 0; i < (width + 3) * 64; i++) {
        tmp[i] = 0;
    }
}