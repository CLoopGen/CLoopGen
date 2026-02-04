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
    src = (uint8_t*)aligned_alloc(64, (height + 3) * srcstride);
    tmp = (int16_t*)aligned_alloc(64, (height + 4) * 64 * sizeof(int16_t));
    filter = (int8_t*)malloc(4 * sizeof(int8_t));

    if (!src || !tmp || !filter) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < (height + 3) * srcstride; i++) {
        src[i] = rand() % 256;
    }

    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 0;

    for (int i = 0; i < (height + 4) * 64; i++) {
        tmp[i] = 0;
    }
}