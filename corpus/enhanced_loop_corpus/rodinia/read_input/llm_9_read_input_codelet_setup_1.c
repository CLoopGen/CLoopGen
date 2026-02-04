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
    // Reduce effective trip count by stepping through every second element
    // and decrease arithmetic operations per iteration
    for (i = 2; i < npoints; i += 2) {
        features[i] = features[i - 2] + nfeatures;
    }
}
