#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t internal_dst[TOTAL_ELEMENTS];
static uint8_t internal_src[TOTAL_ELEMENTS];
static uint8_t internal_cm[256];

void init_vars() {
    const int width = 8;
    const int height = (TOTAL_ELEMENTS / width) / 2; // Divide by 2 to leave room for src/dst and padding

    h = height;

    dstStride = width;
    srcStride = width;

    dst = internal_dst;
    src = internal_src + 2; // Adjust so that src[-2] is valid at start
    cm = internal_cm;

    // Initialize cm lookup table: clamping function, assume input range [-10..10] maps to [0..255]
    for (int j = 0; j < 256; j++) {
        cm[j] = (uint8_t)j;
    }

    // Initialize src with safe values in the middle of the array, ensuring [-2..10] offset access stays in bounds
    for (int y = 0; y < height; y++) {
        uint8_t* src_row = &internal_src[y * srcStride];
        for (int x = -2; x < width + 11; x++) {
            if (x >= -2 && x <= 10) {
                src_row[x] = (uint8_t)((x * 7 + y * 13) % 251);
            }
        }
    }

    // Initialize dst with zeros
    for (int y = 0; y < height; y++) {
        uint8_t* dst_row = &internal_dst[y * dstStride];
        memset(dst_row, 0, width * sizeof(uint8_t));
    }
}