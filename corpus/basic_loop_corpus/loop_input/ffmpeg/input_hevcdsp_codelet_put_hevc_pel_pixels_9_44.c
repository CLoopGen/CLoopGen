#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int height;
int width;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(uint16_t))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)

static uint16_t src_data[TOTAL_ELEMENTS];
static int16_t dst_data[TOTAL_ELEMENTS];

void init_vars() {
    height = 1024;
    width = 512;
    srcstride = 512;

    src = src_data;
    dst = dst_data;

    for (int i = 0; i < TOTAL_ELEMENTS; ++i) {
        src_data[i] = (uint16_t)(i % 32768);
    }
}