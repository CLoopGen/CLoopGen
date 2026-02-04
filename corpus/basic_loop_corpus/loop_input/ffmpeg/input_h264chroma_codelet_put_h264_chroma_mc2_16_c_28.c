#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;
int E;
ptrdiff_t step;

void init_vars() {
    // Set constants for the filter computation
    A = 13;  // example coefficient
    E = 19;  // example coefficient
    step = 1;

    // Determine data size to achieve ~0.01s runtime
    // Assume typical loop overhead and cache behavior
    // Aim for approximately 16 million pixels (e.g., 4K video frame x ~10)
    h = 1 << 14;  // 16384 rows
    int width = 2;  // only two elements accessed per row: index 0 and 1

    // Stride in elements (assume row-major, padding possible)
    stride = width;

    // Allocate source and destination arrays
    size_t total_elements = (size_t)h * width;
    src = aligned_alloc(32, total_elements * sizeof(uint16_t));
    dst = aligned_alloc(32, total_elements * sizeof(uint16_t));

    // Initialize source data to prevent undefined behavior
    for (size_t idx = 0; idx < total_elements; idx++) {
        src[idx] = (uint16_t)(idx % 257);  // small values to avoid overflow
    }

    // Ensure dst is initialized (not strictly needed but good practice)
    for (size_t idx = 0; idx < total_elements; idx++) {
        dst[idx] = 0;
    }
}