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
    if (nclusters <= 1) return;
    for (i = 1; i < nclusters; i++) {
        new_centers[i] = new_centers[i - 1] + nfeatures;
    }
}
