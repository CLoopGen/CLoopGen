#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // Number of iterations: log2(length / 256)
    // On a modern CPU, each iteration is very fast (a few cycles). To achieve ~0.01s,
    // we need enough iterations to accumulate that time. Assume ~1e9 operations/sec,
    // so 0.01s = 1e7 operations. But this loop is only doing comparisons and multiplies.
    // Even 30 iterations would take microseconds. So we must scale length such that
    // other parts (not shown) may depend on data size.

    // Since no array or memory access is visible in the loop, but external context
    // implies data processing, assume the loop is part of a larger algorithm over data.
    // Use 16 MB as data size to ensure measurable runtime if actual work were present.

    // Let's set length to 16 * 1024 * 1024 (16MB) to represent byte-length of data
    length = 16 * 1024 * 1024;
}

// The variable 'extent' is modified in the loop, so no initialization needed beyond what the loop does.