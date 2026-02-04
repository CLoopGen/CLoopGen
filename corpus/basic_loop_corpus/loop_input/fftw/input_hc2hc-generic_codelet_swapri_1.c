#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *IO = NULL;
INT r = 0;
INT s = 0;
INT jstart = 0;
INT jend = 0;
INT k = 0;
INT ms = 0;
INT js = 0;

void init_vars() {
    // Set parameters to ensure valid memory access and ~0.01s runtime
    r = 8192;          // Number of loop iterations in outer loop: k from 0 to r/2
    ms = 16384;        // Stride multiplier for indexing into IO
    js = 8192;         // Offset adjustment to prevent underflow at low indices
    s = 1;             // Step size in inner loop pointer arithmetic
    jstart = 0;        // Inner loop start index
    jend = 1024;       // Inner loop end index (controls inner trip count)

    // Total data size: (r + 1) * ms ensures we cover maximum accessed index
    // Maximum index accessed: (r - k)*ms - js with k=0 -> r*ms - js
    // So allocate at least r*ms elements, plus safety margin for offsets
    size_t total_elements = (size_t)(r * ms) + 1024;
    size_t alloc_bytes = total_elements * sizeof(R);

    // Allocate and initialize array
    IO = (R*)calloc(total_elements, sizeof(R));
    if (!IO) {
        exit(1);
    }

    // Initialize with non-zero values to make swaps observable
    for (size_t i = 0; i < total_elements; ++i) {
        IO[i] = (R)(i & 0xFF);
    }
}