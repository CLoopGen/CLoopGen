#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nclusters;
extern int i;
extern int nthreads;
extern float ***partial_new_centers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 1; i < nthreads; i++) {
        partial_new_centers[i] = partial_new_centers[i - 1] + nclusters;
        for (j = 0; j < nclusters; j++) {
            // Add dummy arithmetic to increase computational intensity
            volatile float dummy = (float)(j * i);
            dummy *= dummy;
        }
    }
}
