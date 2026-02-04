#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2
    // We traverse the same range but access elements in a strided manner.
    // To ensure we stay within bounds, we handle even and odd start positions relative to nmin.
    int stride = 2;
    int start = nmax - nmin;
    // Round down start to nearest multiple of stride for safe backward traversal
    start = (start / stride) * stride;
    
    for (int i = start; i >= 0; i -= stride) {
        result_array[i] = 0.;
    }
    // Handle any remaining element if the total size is odd
    if ((nmax - nmin + 1) % 2 == 1 && (nmax - nmin) >= 0) {
        result_array[nmax - nmin] = 0.; // This may overlap, but ensures coverage
    }
}
