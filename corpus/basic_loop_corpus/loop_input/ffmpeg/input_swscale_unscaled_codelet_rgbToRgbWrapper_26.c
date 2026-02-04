#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int srcSliceY;
int srcSliceH;
int dstStride[1];
uint8_t *dstPtr;
int i;

void init_vars() {
    // Set dimensions to achieve approximately 0.01 seconds runtime
    // Assuming simple memory store, target around 64-128 million operations for modern CPU

    srcSliceY = 1000;
    srcSliceH = 100000;  // 100k iterations

    dstStride[0] = 2048;  // Large stride to increase memory footprint and access time

    // Total memory needed: at least (srcSliceY + srcSliceH - 1 + 1) * dstStride[0] + 1
    size_t min_size = ((size_t)(srcSliceY + srcSliceH - 1) + 1) * dstStride[0] + 1;
    dstPtr = (uint8_t*)aligned_alloc(32, min_size);
    if (!dstPtr) {
        exit(1);
    }

    // Initialize destination memory to zero for predictable behavior
    for (size_t idx = 0; idx < min_size; idx++) {
        dstPtr[idx] = 0;
    }
}