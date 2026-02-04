#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
#define ELEMENT_SIZE sizeof(uint16_t)
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

static uint16_t top_data[TOTAL_ELEMENTS];
static uint16_t bottom_data[TOTAL_ELEMENTS];
static uint16_t dst_data[TOTAL_ELEMENTS];

void init_vars() {
    width = 2048;
    height = (TOTAL_ELEMENTS + width - 1) / width;
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    opacity = 0.5;

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    for (int idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        top_data[idx] = rand() % 4096;
        bottom_data[idx] = rand() % 4096;
        dst_data[idx] = 0;
    }
}