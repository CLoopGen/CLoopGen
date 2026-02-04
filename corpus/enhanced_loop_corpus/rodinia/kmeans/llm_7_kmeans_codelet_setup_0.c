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
    if (temp == NULL) return;
    temp[0] = features[0];
    for (int k = 1; k < npoints; k++) {
        temp[k] = temp[k - 1] + nfeatures;
        features[k] = temp[k];
    }
    free(temp);
}
