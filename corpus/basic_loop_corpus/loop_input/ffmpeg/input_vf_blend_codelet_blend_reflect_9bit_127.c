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

static uint16_t *top_data;
static uint16_t *bottom_data;
static uint16_t *dst_data;

void init_vars() {
    // Target: ~0.01 seconds runtime -> aim for moderate data size
    // Heuristic: Use ~16-32 million pixels (e.g., 4K video frame scale)
    width = 4096;
    height = 4096;

    // Ensure non-zero divisors and valid ranges
    opacity = 0.75;

    // Linesizes in bytes? But we use uint16_t*, so step in elements
    // Assume linesize is in units of uint16_t elements
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_elements = width * height;
    size_t total_bytes = total_elements * sizeof(uint16_t);

    // Allocate aligned memory to avoid issues
    top_data = aligned_alloc(64, total_bytes);
    bottom_data = aligned_alloc(64, total_bytes);
    dst_data = aligned_alloc(64, total_bytes);

    // Initialize pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    // Initialize data: ensure no division by zero (511 - bottom[j] != 0)
    for (size_t idx = 0; idx < total_elements; idx++) {
        top_data[idx] = rand() % 511; // 0..510 to avoid 511 causing conditional trigger
        bottom_data[idx] = rand() % 510; // 0..509 so that (511 - bottom[j]) >= 2
    }
}