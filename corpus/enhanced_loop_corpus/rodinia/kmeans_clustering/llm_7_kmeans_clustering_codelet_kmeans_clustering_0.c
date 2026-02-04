#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern float **clusters;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nclusters > 1) {
        clusters[1] = clusters[0] + nfeatures;
        for (i = 2; i < nclusters; i++) {
            clusters[i] = clusters[i - 2] + nfeatures * 2;
        }
    }
}
