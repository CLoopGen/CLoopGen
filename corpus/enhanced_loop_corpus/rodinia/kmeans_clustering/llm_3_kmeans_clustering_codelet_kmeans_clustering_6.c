#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nclusters;
extern int i;
extern int nthreads;
extern float ***partial_new_centers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — update indices with a stride of 2, then handle remainder
    int stride = 2;
    // First pass: strided access (even indices)
    for (i = 1; i < nthreads; i += stride) {
        partial_new_centers[i] = partial_new_centers[i - 1] + nclusters;
    }
    // Second pass: fill in the gaps (odd indices within bounds)
    for (i = 2; i < nthreads; i += stride) {
        if (i - 1 >= 1) {
            partial_new_centers[i - 1] = partial_new_centers[i - 2] + nclusters;
        }
    }
}
