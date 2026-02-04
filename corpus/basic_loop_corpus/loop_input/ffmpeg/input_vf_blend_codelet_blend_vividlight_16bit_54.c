#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity;
int i;
int j;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

static uint16_t buffer_top[TOTAL_ELEMENTS];
static uint16_t buffer_bottom[TOTAL_ELEMENTS];
static uint16_t buffer_dst[TOTAL_ELEMENTS];

void init_vars() {
    width = 1024;
    height = (TOTAL_ELEMENTS / width);
    
    if (height * width > TOTAL_ELEMENTS) {
        height = TOTAL_ELEMENTS / width;
    }

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    top = buffer_top;
    bottom = buffer_bottom;
    dst = buffer_dst;

    for (size_t idx = 0; idx < (size_t)(height * width); idx++) {
        buffer_top[idx] = rand() % 65536;
        buffer_bottom[idx] = rand() % 65536;
        buffer_dst[idx] = 0;
    }
}