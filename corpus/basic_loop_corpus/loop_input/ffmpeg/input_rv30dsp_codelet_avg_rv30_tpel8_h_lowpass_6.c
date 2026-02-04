#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int C1 = 17;
int C2 = 35;
int h;
uint8_t *cm;
int i;

static uint8_t internal_dst[TOTAL_ELEMENTS];
static uint8_t internal_src[TOTAL_ELEMENTS];
static uint8_t internal_cm[256];

void init_vars() {
    const int width = 8;
    const int height = TOTAL_ELEMENTS / width;
    h = height;

    dstStride = width;
    srcStride = width;

    dst = internal_dst;
    src = internal_src;
    cm = internal_cm;

    for (int i = 0; i < 256; i++) {
        cm[i] = (uint8_t)(i * i % 256);
    }

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        internal_dst[i] = (uint8_t)(i % 256);
        internal_src[i] = (uint8_t)((i + 42) % 256);
    }
}