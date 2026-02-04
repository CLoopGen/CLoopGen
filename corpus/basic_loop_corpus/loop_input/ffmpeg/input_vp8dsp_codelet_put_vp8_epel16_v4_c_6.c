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
#define HEIGHT_FACTOR 1024
#define WIDTH 16

static uint8_t internal_dst[HEIGHT_FACTOR][16];
static uint8_t internal_src[HEIGHT_FACTOR + 2][16 + 2]; // Add padding for -1 and +2 offsets
static uint8_t internal_filter[FILTER_SIZE];
static uint8_t internal_cm[CM_SIZE];

void init_vars() {
    // Initialize filter values to reasonable coefficients (e.g., symmetric low-pass)
    internal_filter[0] = 0;  // unused
    internal_filter[1] = 16;
    internal_filter[2] = 32;
    internal_filter[3] = 16;
    internal_filter[4] = 8;

    // Initialize cm table: identity mapping with clipping
    for (int i = 0; i < CM_SIZE; i++) {
        internal_cm[i] = (i < 256) ? i : 255;
    }

    // Initialize source data with non-zero values
    for (int i = 0; i < HEIGHT_FACTOR + 2; i++) {
        for (int j = 0; j < 16 + 2; j++) {
            internal_src[i][j] = rand() & 0xFF;
        }
    }

    // Set up pointers
    dst = &internal_dst[0][0];
    src = &internal_src[1][1]; // middle of padding to allow [-1] and [+2] indexing
    dststride = 16;
    srcstride = 16 + 2;
    h = HEIGHT_FACTOR;
    filter = internal_filter;
    cm = internal_cm;
}