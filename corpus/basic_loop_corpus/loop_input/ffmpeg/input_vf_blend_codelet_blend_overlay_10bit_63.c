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

static uint16_t *top_data;
static uint16_t *bottom_data;
static uint16_t *dst_data;

void init_vars() {
    // Set parameters for ~0.01s runtime on modern CPU
    // Estimated operations per cycle: ~4 FLOPs, 3-4 memory ops
    // Target: ~100M elements should be sufficient (~0.01s at 10G op/s)

    width = 2048;
    height = 128;
    opacity = 0.5;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t data_size = width * height * sizeof(uint16_t);

    // Allocate aligned memory to avoid issues and improve performance
    top_data = aligned_alloc(32, data_size);
    bottom_data = aligned_alloc(32, data_size);
    dst_data = aligned_alloc(32, data_size);

    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize with non-zero pattern to allow meaningful computation
    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (uint16_t)(idx % 1024);
        bottom_data[idx] = (uint16_t)((idx * 7) % 1024);
        dst_data[idx] = 0;
    }

    // Point the external pointers to allocated buffers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}