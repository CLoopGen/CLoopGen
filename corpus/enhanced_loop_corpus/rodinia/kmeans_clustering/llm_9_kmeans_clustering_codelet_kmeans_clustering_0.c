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
    // Reduce effective trip count by skipping every other element
    // Also reduce computational operations per iteration
    for (i = 2; i < nclusters; i += 2) {
        clusters[i] = clusters[i - 2] + 2 * nfeatures;
    }
}
