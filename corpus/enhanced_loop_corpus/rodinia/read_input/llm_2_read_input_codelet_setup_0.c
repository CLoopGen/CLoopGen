#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int npoints;
extern float **features;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive rows, access every second row in a forward manner.
    // This creates a strided access pattern with stride 2 for both source and destination.
    int stride = 2;
    for (i = stride; i < npoints; i += stride) {
        if (i - stride >= 0) {
            features[i] = features[i - stride] + nfeatures;
        }
    }
    // Handle remaining elements if npoints is not divisible by stride
    if ((npoints % 2 == 1) && (npoints > 1)) {
        features[npoints - 1] = features[npoints - 2] + nfeatures;
    }
}
