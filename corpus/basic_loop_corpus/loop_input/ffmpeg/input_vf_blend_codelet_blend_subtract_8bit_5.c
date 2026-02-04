#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

#define DATA_WIDTH 1920
#define DATA_HEIGHT 1080

static uint8_t *top_data;
static uint8_t *bottom_data;
static uint8_t *dst_data;

void init_vars() {
    width = DATA_WIDTH;
    height = DATA_HEIGHT;
    opacity = 0.5;
    top_linesize = width * sizeof(uint8_t);
    bottom_linesize = width * sizeof(uint8_t);
    dst_linesize = width * sizeof(uint8_t);

    top_data = aligned_alloc(32, height * top_linesize);
    bottom_data = aligned_alloc(32, height * bottom_linesize);
    dst_data = aligned_alloc(32, height * dst_linesize);

    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (ptrdiff_t i = 0; i < height; i++) {
        for (ptrdiff_t j = 0; j < width; j++) {
            top_data[i * width + j] = rand() % 256;
            bottom_data[i * width + j] = rand() % 256;
            dst_data[i * width + j] = 0;
        }
    }

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}