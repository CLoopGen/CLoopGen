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
    // Eliminate loop-carried dependencies entirely by making each iteration independent
    // Each features[i] is computed directly from base pointer and index, removing dependence on previous iterations
    if (npoints <= 1) return;
    for (int i = 1; i < npoints; i++) {
        features[i] = features[0] + i * nfeatures;
    }
}
