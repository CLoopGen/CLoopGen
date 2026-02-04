#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int8_t *filter = filter_data;

uint8_t *src;
ptrdiff_t srcstride;

int16_t *tmp;

void init_vars() {
    srcstride = width + 8;

    src = aligned_alloc(64, (height + 7) * srcstride * sizeof(uint8_t));
    tmp = aligned_alloc(64, (height + 7) * 64 * sizeof(int16_t));

    for (int i = 0; i < (height + 7) * srcstride; i++) {
        src[i] = rand() % 256;
    }
}