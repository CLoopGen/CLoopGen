#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern float **new_centers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *prev_center = new_centers[0];
    for (i = 1; i < nclusters; i++) {
        prev_center = prev_center + nfeatures;
        new_centers[i] = prev_center;
    }
}
