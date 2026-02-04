#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint8_t *top;
ptrdiff_t top_linesize;
uint8_t *bottom;
ptrdiff_t bottom_linesize;
uint8_t *dst;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
double opacity;
int i;
int j;

static uint8_t *top_data;
static uint8_t *bottom_data;
static uint8_t *dst_data;

void init_vars() {
    width = 1920;
    height = 1080;
    opacity = 0.5;
    top_linesize = width * sizeof(uint8_t);
    bottom_linesize = width * sizeof(uint8_t);
    dst_linesize = width * sizeof(uint8_t);

    size_t total_size = (size_t)width * (size_t)height * sizeof(uint8_t);

    top_data = calloc(total_size, 1);
    bottom_data = calloc(total_size, 1);
    dst_data = calloc(total_size, 1);

    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        top_data[idx] = rand() % 256;
        bottom_data[idx] = rand() % 256;
    }

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}