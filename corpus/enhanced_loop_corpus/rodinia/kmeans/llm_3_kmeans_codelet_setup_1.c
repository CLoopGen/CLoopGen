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
    // Variant 2: Reverse consecutive access - iterate from end to beginning with unit stride
    for (i = npoints - 1; i >= 1; i--)
        features[i] = features[i - 1] + nfeatures;
}
