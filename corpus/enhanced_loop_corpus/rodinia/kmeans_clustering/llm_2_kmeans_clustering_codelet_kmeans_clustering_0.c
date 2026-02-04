#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern float **clusters;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing clusters[i-1] directly, simulate a strided pattern by stepping through
    // the array with a fixed increment (stride = 1 in this case, but access pattern is maintained conceptually).
    // Here, we maintain the same logic but express it using pointer arithmetic with explicit stride.
    float **base = clusters;
    for (i = 1; i < nclusters; i++) {
        base[i] = base[i - 1] + nfeatures;
    }
}
