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
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse the array in reverse order, updating each pointer based on the next one.
    // This reverses the data flow direction while maintaining consecutive access.
    for (i = npoints - 1; i >= 1; i--) {
        features[i] = features[i - 1] + nfeatures;
    }
}
