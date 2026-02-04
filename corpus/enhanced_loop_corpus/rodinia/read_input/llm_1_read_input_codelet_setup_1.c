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
    int outer_i;
    for (outer_i = 1; outer_i < npoints; outer_i++) {
        i = outer_i;
        features[i] = features[i - 1] + nfeatures;
    }
}
