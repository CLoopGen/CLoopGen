#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **feature;
extern int nfeatures;
extern int nclusters;
extern int i;
extern int j;
extern int n;
extern int temp;
extern float **clusters;
extern int *initial;
extern int initial_points;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried dependency by making 'n' update before use, creating a WAW and RAW dependency
    // Also restructure to ensure clusters[i][j] computation depends on prior iteration's initial modification
    for (i = 0; i < nclusters && initial_points >= 0; i++) {
        temp = initial[n];
        // Swap first, so that next use of 'n' sees updated array state
        initial[n] = initial[initial_points - 1];
        initial[initial_points - 1] = temp;
        // Now use the swapped index from updated 'n' position
        for (j = 0; j < nfeatures; j++)
            clusters[i][j] = feature[initial[n]][j];  // now reads after write to initial[n]
        initial_points--;
        n++;  // increment after use in feature indexing
    }
}
