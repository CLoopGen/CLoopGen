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
    int j;
    for (i = 1; i < nclusters; i++) {
        new_centers[i] = new_centers[i - 1] + nfeatures;
        // Additional arithmetic to increase computational intensity
        for (j = 0; j < nfeatures; j++) {
            float val = *(new_centers[i] + j);
            val = val * val + 0.1f;
            *(new_centers[i] + j) = val;
        }
    }
}
