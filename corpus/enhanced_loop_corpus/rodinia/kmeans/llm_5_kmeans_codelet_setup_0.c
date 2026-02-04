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
    for (i = 1; i < npoints; i++) {
        if (features[i - 1] != NULL) {
            features[i] = features[i - 1] + nfeatures;
        } else {
            features[i] = NULL;
        }
    }
}
