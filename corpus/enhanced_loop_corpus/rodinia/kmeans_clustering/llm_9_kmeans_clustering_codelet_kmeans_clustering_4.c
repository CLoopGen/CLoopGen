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
    // Reduce effective trip count by skipping every other element
    // and perform a single pointer assignment with no inner operations
    for (i = 2; i < nclusters; i += 2)
        new_centers[i] = new_centers[i - 2] + 2 * nfeatures;
}
