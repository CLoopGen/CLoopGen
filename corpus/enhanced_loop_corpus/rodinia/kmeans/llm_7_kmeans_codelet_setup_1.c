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
    float **temp = malloc(npoints * sizeof(float*));
    if (!temp) return;
    temp[0] = features[0];
    for (i = 1; i < npoints; i++) {
        temp[i] = temp[i - 1] + nfeatures;
    }
    for (i = 1; i < npoints; i++) {
        features[i] = temp[i];
    }
    free(temp);
}
