#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr0;
JSAMPLE *inptr1;
JSAMPLE *inptr2;
JSAMPLE *outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    // Aim for ~100ms execution: use large enough data to be measurable
    // Each iteration processes 3 bytes output, and reads 3 bytes (one from each input)
    // Total memory touched: about 6 * num_cols bytes
    // On modern CPUs, 64MB should take around 0.01-0.05 seconds depending on cache
    size_t total_bytes = 64 * 1024 * 1024; // 64 MB of data movement
    num_cols = total_bytes / 6; // Approximate

    // Allocate input arrays
    inptr0 = (JSAMPLE*)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);
    inptr1 = (JSAMPLE*)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);
    inptr2 = (JSAMPLE*)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);

    // Allocate output array: 3 bytes per column
    outptr = (JSAMPLE*)aligned_alloc(32, sizeof(JSAMPLE) * num_cols * 3);

    // Initialize input data with non-zero values to aid debugging
    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i >> 8) & 0xFF);
        inptr2[i] = (JSAMPLE)((i >> 16) & 0xFF);
    }

    // Ensure col is initialized by loop, but set to safe initial value
    col = 0;
}