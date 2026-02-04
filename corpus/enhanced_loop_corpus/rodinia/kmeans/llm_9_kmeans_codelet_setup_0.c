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
    // Reduce effective trip count by striding through the data
    int stride = 2;
    for (i = stride; i < npoints; i += stride) {
        features[i] = features[i - stride] + nfeatures;
    }
    // Handle any remaining element if npoints is odd
    if (npoints > 1 && (npoints % stride) == 1) {
        features[npoints - 1] = features[npoints - 2] + nfeatures;
    }
}
