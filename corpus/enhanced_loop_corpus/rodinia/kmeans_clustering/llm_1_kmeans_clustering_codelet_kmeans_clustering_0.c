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
    int outer_i;
    for (outer_i = 1; outer_i < nclusters; outer_i++) {
        i = outer_i;
        clusters[i] = clusters[i - 1] + nfeatures;
    }
}
