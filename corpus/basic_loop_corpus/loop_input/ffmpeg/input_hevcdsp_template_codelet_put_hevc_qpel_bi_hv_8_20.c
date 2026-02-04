#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 64;
int width = 64;
int x;
int y;

int8_t *filter;
uint8_t *src;
ptrdiff_t srcstride = 64;
int16_t *tmp;

void init_vars() {
    filter = (int8_t*)aligned_alloc(32, 8 * sizeof(int8_t));
    src = (uint8_t*)aligned_alloc(32, (height + 7) * srcstride + 10);
    tmp = (int16_t*)aligned_alloc(32, (width + 64) * 64 * sizeof(int16_t));

    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i - 3);
    }

    for (int i = 0; i < (height + 7) * srcstride + 10; i++) {
        src[i] = (uint8_t)(i % 256);
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}