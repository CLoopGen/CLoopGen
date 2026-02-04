#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dststride;
uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20))

static uint8_t internal_dst[TOTAL_ELEMENTS];
static uint8_t internal_src[TOTAL_ELEMENTS];
static uint8_t internal_filter[5];
static uint8_t internal_cm[256];

void init_vars() {
    const int width = 4;
    const int filter_size = 5;

    h = TOTAL_ELEMENTS / width;
    dststride = width;
    srcstride = width;

    dst = internal_dst;
    src = internal_src;
    filter = internal_filter;
    cm = internal_cm;

    for (int i = 0; i < filter_size; i++) {
        filter[i] = rand() & 0xFF;
    }

    for (int i = 0; i < 256; i++) {
        cm[i] = rand() & 0xFF;
    }

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        src[i] = rand() & 0xFF;
    }

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        dst[i] = 0;
    }
}