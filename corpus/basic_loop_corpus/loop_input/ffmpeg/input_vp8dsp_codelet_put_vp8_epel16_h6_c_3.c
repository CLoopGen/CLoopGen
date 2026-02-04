#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
#define WIDTH 16
#define HEIGHT 32768

static uint8_t internal_dst[HEIGHT * WIDTH] __attribute__((aligned(32)));
static uint8_t internal_src[HEIGHT * WIDTH] __attribute__((aligned(32)));
static uint8_t internal_filter[FILTER_SIZE] = {8, 12, 20, 24, 18, 10};
static uint8_t internal_cm[CM_SIZE];

void init_vars() {
    dst = internal_dst;
    src = internal_src;
    filter = internal_filter;
    cm = internal_cm;
    dststride = WIDTH * sizeof(uint8_t);
    srcstride = WIDTH * sizeof(uint8_t);
    h = HEIGHT;

    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        src[i] = (uint8_t)(i % 256);
    }

    memset(dst, 0, HEIGHT * WIDTH * sizeof(uint8_t));
}