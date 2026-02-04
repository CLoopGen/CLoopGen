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

#define FILTER_SIZE 6
#define CM_SIZE 256
#define WIDTH 8
#define HEIGHT 32768

static uint8_t internal_dst[HEIGHT * WIDTH] __attribute__((aligned(32)));
static uint8_t internal_src[HEIGHT * WIDTH] __attribute__((aligned(32)));
static uint8_t internal_filter[FILTER_SIZE] = {1, 2, 3, 4, 5, 6};
static uint8_t internal_cm[CM_SIZE];

void init_vars() {
    for (int i = 0; i < FILTER_SIZE; i++) {
        internal_filter[i] = (uint8_t)(i + 1);
    }
    for (int i = 0; i < CM_SIZE; i++) {
        internal_cm[i] = (uint8_t)i;
    }
    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        internal_src[i] = (uint8_t)(i % 256);
    }

    dst = internal_dst;
    src = internal_src;
    filter = internal_filter;
    cm = internal_cm;
    dststride = WIDTH;
    srcstride = WIDTH;
    h = HEIGHT;
}