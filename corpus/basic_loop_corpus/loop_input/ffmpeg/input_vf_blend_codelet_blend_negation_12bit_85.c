#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
#define ELEMENT_SIZE sizeof(uint16_t)
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

static uint16_t *top_data;
static uint16_t *bottom_data;
static uint16_t *dst_data;

void init_vars() {
    opacity = 0.5;
    height = sqrt(TOTAL_ELEMENTS / 4);
    width = sqrt(TOTAL_ELEMENTS / 4);

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t alloc_size = width * height * ELEMENT_SIZE;

    top_data = aligned_alloc(32, alloc_size);
    bottom_data = aligned_alloc(32, alloc_size);
    dst_data = aligned_alloc(32, alloc_size);

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = rand() % 4096;
        bottom_data[idx] = rand() % 4096;
    }
}