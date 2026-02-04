#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dststride;
uint8_t *src;
ptrdiff_t srcstride;
int h = 1024;
uint8_t *filter;
uint8_t *cm;
int x;
int y;

static uint8_t internal_dst[1024 * 1024];
static uint8_t internal_src[1024 * 1024 + 8];
static uint8_t internal_filter[5] = {0, 8, 16, 8, 0};
static uint8_t internal_cm[512];

void init_vars() {
    dststride = 1024;
    srcstride = 1024;
    dst = internal_dst;
    src = internal_src + 4;
    filter = internal_filter;
    cm = internal_cm + 256;

    for (int i = 0; i < 1024 * 1024; i++) {
        internal_dst[i] = 0;
    }
    for (int i = 0; i < 1024 * 1024 + 8; i++) {
        internal_src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 512; i++) {
        internal_cm[i] = (i < 0 || i >= 512) ? 0 : (uint8_t)((i - 256 + 256) & 0xFF);
    }
}