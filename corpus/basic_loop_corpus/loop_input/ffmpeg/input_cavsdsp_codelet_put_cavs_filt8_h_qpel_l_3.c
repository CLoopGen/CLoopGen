#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20))
#define SRC_HEIGHT 4096
#define SRC_WIDTH 16
#define DST_WIDTH 8

static uint8_t internal_src[SRC_HEIGHT][SRC_WIDTH + 20]; // extra padding for negative/positive offsets
static uint8_t internal_dst[SRC_HEIGHT][DST_WIDTH];
static uint8_t internal_cm[512]; // extended range to prevent out-of-bounds in cm[] indexing

void init_vars() {
    // Initialize constants
    h = SRC_HEIGHT;
    dstStride = sizeof(internal_dst[0]);
    srcStride = sizeof(internal_src[0]);

    // Point to actual data
    src = &internal_src[0][-2]; // Adjust so that [-2] is valid at start
    dst = &internal_dst[0][0];

    cm = &internal_cm[256]; // Center cm access around zero; allows [-256..255]

    // Initialize cm table: clamp values to [0,255]
    for (int idx = -256; idx < 256; idx++) {
        int val = (idx < 0) ? 0 : (idx > 255) ? 255 : idx;
        cm[idx] = (uint8_t)val;
    }

    // Initialize src with smooth gradient pattern to avoid extreme edge effects
    for (int y = 0; y < SRC_HEIGHT; y++) {
        for (int x = 0; x < SRC_WIDTH + 20; x++) {
            internal_src[y][x] = (uint8_t)((x + y) & 0xFF);
        }
    }

    // Clear destination
    for (int y = 0; y < SRC_HEIGHT; y++) {
        for (int x = 0; x < DST_WIDTH; x++) {
            internal_dst[y][x] = 0;
        }
    }

    // Initialize loop counter
    i = 0;
}