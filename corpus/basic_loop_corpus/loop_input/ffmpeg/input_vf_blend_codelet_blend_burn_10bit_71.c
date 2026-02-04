#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define TOTAL_SIZE (128 * 1024 * 1024) // Aim for ~128MB of total data

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

void init_vars() {
    // Set dimensions to control total memory usage
    height = 4096;
    width = 8192;

    // Ensure each row fits within width and linesizes allow for padding or alignment
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    // Allocate memory for three 2D arrays: top, bottom, dst
    size_t total_elements = height * width;
    size_t total_bytes = total_elements * sizeof(uint16_t);

    // Allocate aligned or plain memory
    top = (uint16_t*)aligned_alloc(64, total_bytes);
    bottom = (uint16_t*)aligned_alloc(64, total_bytes);
    dst = (uint16_t*)aligned_alloc(64, total_bytes);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize array contents with non-trivial but valid values
    for (size_t idx = 0; idx < total_elements; idx++) {
        top[idx] = rand() % 1024;
        bottom[idx] = rand() % 1024;
    }

    // Set opacity to a mid-range value between 0.0 and 1.0
    opacity = 0.75;

    // Ensure no pending issues from previous runs
    i = 0;
    j = 0;
}