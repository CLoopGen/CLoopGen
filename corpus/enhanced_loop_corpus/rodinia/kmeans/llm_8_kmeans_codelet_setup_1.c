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
    for (i = 2; i < npoints; i += 2) {
        features[i] = features[i - 1] + nfeatures;
        if (i + 1 < npoints)
            features[i + 1] = features[i] + nfeatures;
    }
}
