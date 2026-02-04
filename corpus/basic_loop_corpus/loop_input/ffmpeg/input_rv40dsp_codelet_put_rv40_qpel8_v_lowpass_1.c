#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int C1;
int C2;
int SHIFT;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024)

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];
static uint8_t internal_cm[256];

void init_vars() {
    dstStride = 1;
    srcStride = 1;
    w = DATA_SIZE / 16;  
    C1 = 20;
    C2 = 10;
    SHIFT = 6;

    cm = internal_cm;
    dst = internal_dst;
    src = internal_src + 10 * srcStride;

    for (int i = 0; i < 256; ++i) {
        cm[i] = (uint8_t)i;
    }

    for (int i = 0; i < DATA_SIZE; ++i) {
        internal_dst[i] = 0;
        internal_src[i] = rand() & 0xFF;
    }
}