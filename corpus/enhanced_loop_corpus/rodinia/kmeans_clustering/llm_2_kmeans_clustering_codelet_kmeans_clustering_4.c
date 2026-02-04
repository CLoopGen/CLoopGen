#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern float **new_centers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential pointer assignment, use strided indexing with a step of 2 (unrolling effect)
    // This variant processes elements in a non-consecutive but predictable stride.
    for (i = 2; i < nclusters; i += 2) {
        new_centers[i - 1] = new_centers[i - 2] + nfeatures;
        if (i < nclusters) {
            new_centers[i] = new_centers[i - 1] + nfeatures;
        }
    }
    // Handle any odd-sized nclusters by ensuring the first element is set if needed
    if (nclusters > 1 && (nclusters % 2 == 0)) {
        new_centers[nclusters - 1] = new_centers[nclusters - 2] + nfeatures;
    }
}
