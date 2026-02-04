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
#define HEIGHT (1 << 14)  // Approximately 16k rows to ensure ~0.01s runtime

static uint8_t internal_dst[HEIGHT * WIDTH];
static uint8_t internal_src[HEIGHT * 3 + 4][WIDTH];  // Add padding for -2, -1, +1, +2, +3 offsets
static uint8_t internal_filter[FILTER_SIZE] = {1, 2, 3, 4, 5, 6};
static uint8_t internal_cm[CM_SIZE];

void init_vars() {
    dst = internal_dst;
    src = &internal_src[2][0];  // Point to first valid row accounting for -2 offset
    dststride = WIDTH * sizeof(uint8_t);
    srcstride = WIDTH * sizeof(uint8_t);
    h = HEIGHT;
    filter = internal_filter;
    cm = internal_cm;

    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    for (int i = 0; i < HEIGHT + 4; i++) {
        for (int j = 0; j < WIDTH; j++) {
            internal_src[i][j] = rand() & 0xFF;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            internal_dst[i * WIDTH + j] = 0;
        }
    }
}