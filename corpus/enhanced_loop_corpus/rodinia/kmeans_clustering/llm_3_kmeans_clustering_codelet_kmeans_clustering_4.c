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
    // Variant 2: Indirect memory access using an index map (simulated via offset array)
    // Introduce an auxiliary index array to access new_centers in a shuffled order
    // This simulates indirect or random-access patterns often seen in sparse computations
    int *indices = (int*)malloc(nclusters * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create a simple indirect access order: reverse traversal indices
    for (int j = 0; j < nclusters; j++) {
        indices[j] = nclusters - 1 - j;
    }

    // Traverse in reverse logical order using the index map
    for (i = 1; i < nclusters; i++) {
        int current = indices[i];
        int prev = indices[i - 1];
        new_centers[current] = new_centers[prev] + nfeatures;
    }

    free(indices);
}
