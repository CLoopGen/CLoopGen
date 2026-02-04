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
    for (i = 1; i < npoints; i++) {
        features[i] = features[i - 1] + nfeatures;
        // Additional arithmetic to increase computational intensity
        for (j = 0; j < nfeatures; j++) {
            features[i][j] += (float)(j * 2);
        }
    }
}
