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
    int j;
    for (j = 1; j < npoints; j++) {
        features[j] = features[0] + j * nfeatures;
    }
}
