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
    // Variant 2: Indirect Memory Access Pattern via Index Array
    // Introduce an auxiliary index array to access clusters indirectly.
    // This simulates scenarios where memory access is not sequential in the index space.
    int *indices = (int*)malloc(nclusters * sizeof(int));
    for (int j = 0; j < nclusters; j++) {
        indices[j] = j;
    }
    for (i = 1; i < nclusters; i++) {
        int curr = indices[i];
        int prev = indices[i - 1];
        clusters[curr] = clusters[prev] + nfeatures;
    }
    free(indices);
}
