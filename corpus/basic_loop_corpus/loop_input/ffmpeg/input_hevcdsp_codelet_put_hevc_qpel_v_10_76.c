#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int height;
int width;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride;
int8_t *filter;

void init_vars() {
    width = 64;
    height = 4000;
    srcstride = 64;

    filter = (int8_t*)malloc(8 * sizeof(int8_t));
    src = (uint16_t*)malloc((height + 7) * srcstride * sizeof(uint16_t));
    dst = (int16_t*)malloc(height * 64 * sizeof(int16_t));

    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i == 4 ? 64 : 0);
    }

    for (int i = 0; i < (height + 7) * srcstride; i++) {
        src[i] = rand() & 0x3FF;
    }
}

void loop();