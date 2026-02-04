#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
ptrdiff_t dststride;
uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;

#define FILTER_SIZE 5
#define CM_SIZE 256
#define HEIGHT_SCALE 1000
#define WIDTH 8

void init_vars() {
    h = HEIGHT_SCALE;
    dststride = 16;
    srcstride = 16;

    dst = aligned_alloc(32, dststride * h);
    src = aligned_alloc(32, srcstride * (h + 2));

    filter = malloc(FILTER_SIZE * sizeof(uint8_t));
    cm = malloc(CM_SIZE * sizeof(uint8_t));

    for (int i = 0; i < FILTER_SIZE; i++) {
        filter[i] = (i == 0) ? 0 : (i == 1 || i == 4) ? 16 : 32;
    }

    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    memset(dst, 0, dststride * h);
    memset(src, 0, srcstride * (h + 2));
}