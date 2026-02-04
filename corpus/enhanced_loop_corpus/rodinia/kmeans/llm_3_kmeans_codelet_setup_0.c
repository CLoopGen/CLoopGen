#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int npoints;
extern float **features;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) memory access using an index map
    // Simulate indirect access via an auxiliary index array to reorder access
    int *index_map = (int*)malloc(npoints * sizeof(int));
    if (!index_map) return; // Handle allocation failure

    // Create reverse order access map (indirect traversal from end to start)
    for (int j = 0; j < npoints; j++) {
        index_map[j] = npoints - 1 - j;
    }

    // Traverse in reverse logical order using the index map
    for (i = 1; i < npoints; i++) {
        int curr = index_map[i];
        int prev = index_map[i - 1];
        features[curr] = features[prev] + nfeatures;
    }

    free(index_map);
}
