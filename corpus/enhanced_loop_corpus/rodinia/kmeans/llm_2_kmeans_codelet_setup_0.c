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
    // Variant 1: Strided memory access pattern
    // Instead of accessing features[i-1] sequentially, we access with a stride of 2
    // This creates a strided access pattern in the pointer array
    for (i = 2; i < npoints; i += 2) {
        features[i] = features[i - 2] + nfeatures;
        if (i + 1 < npoints)
            features[i + 1] = features[i - 1] + nfeatures;
    }
    // Handle odd-sized npoints by updating last element if needed
    if (npoints % 2 == 0 && npoints > 1)
        features[npoints - 1] = features[npoints - 2] + nfeatures;
}
