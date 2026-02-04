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

#define FILTER_SIZE 5
#define CM_SIZE 256
#define SRC_WIDTH 16
#define SRC_HEIGHT 4096
#define DST_WIDTH 16

static uint8_t internal_dst[DST_WIDTH * SRC_HEIGHT];
static uint8_t internal_src[SRC_WIDTH * SRC_HEIGHT];
static uint8_t internal_filter[FILTER_SIZE] = {1, 2, 3, 4, 5};
static uint8_t internal_cm[CM_SIZE];

void init_vars() {
    dststride = DST_WIDTH;
    srcstride = SRC_WIDTH;
    h = SRC_HEIGHT;

    filter = internal_filter;
    cm = internal_cm;
    dst = internal_dst;
    src = internal_src;

    for (int i = 0; i < SRC_WIDTH * SRC_HEIGHT; i++) {
        src[i] = rand() & 0xFF;
    }

    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = i;
    }
}