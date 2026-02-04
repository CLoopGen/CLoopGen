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
    if (npoints <= 1) return;
    for (i = 1; i < npoints; i++) {
        features[i] = features[i - 1] + nfeatures;
        // Introduce a temporary variable that creates a WAW dependency on features[i]
        float* temp = features[i];
        // Artificially create a write-after-write by reassigning (redundant but valid)
        features[i] = temp;
    }
}
