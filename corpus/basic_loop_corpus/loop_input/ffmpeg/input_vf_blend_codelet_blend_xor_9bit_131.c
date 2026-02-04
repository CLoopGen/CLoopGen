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

void init_vars() {
    // Set reasonable dimensions for ~0.01s runtime: aim for moderate size (~10-20 MPix total)
    width = 2048;
    height = 512;

    // Ensure linesizes are in units of uint16_t elements, not bytes
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate aligned memory to avoid padding issues and ensure safety
    size_t total_size = width * height * sizeof(uint16_t);

    top = aligned_alloc(64, total_size);
    bottom = aligned_alloc(64, total_size);
    dst = aligned_alloc(64, total_size);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with predictable patterns to avoid undefined behavior
    for (size_t idx = 0; idx < width * height; idx++) {
        top[idx] = (uint16_t)(idx & 0xFFFF);
        bottom[idx] = (uint16_t)((idx * 3) & 0xFFFF);
        dst[idx] = 0;
    }
}