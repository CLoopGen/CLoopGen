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
    src = aligned_alloc(32, sizeof(uint8_t) * (height + 3) * srcstride);
    filter = aligned_alloc(32, sizeof(int8_t) * 4);
    tmp = aligned_alloc(32, sizeof(int16_t) * width * (height + 3));

    for (int i = 0; i < 4; i++) {
        filter[i] = 1 << (8 - 2); // e.g., 64 to make sum ~256 after shift
    }

    for (int i = 0; i < (height + 3) * srcstride; i++) {
        src[i] = rand() % 256;
    }
}