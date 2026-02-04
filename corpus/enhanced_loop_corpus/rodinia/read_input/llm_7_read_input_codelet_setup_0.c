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
    // Remove loop-carried dependency by making each iteration independent
    // Instead of chaining pointers from previous iteration, compute directly from base
    if (npoints < 1) return;
    for (i = 1; i < npoints; i++) {
        features[i] = features[0] + i * nfeatures;
    }
}
