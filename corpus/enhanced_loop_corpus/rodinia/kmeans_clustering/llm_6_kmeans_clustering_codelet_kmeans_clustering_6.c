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
    // Variant 1: Introduce a loop-carried WAW dependency by reordering write operations
    // and ensuring each iteration waits for the previous write to complete.
    // This creates a write-after-write dependency on partial_new_centers[i-1].
    float ***temp = (float ***)malloc(nthreads * sizeof(float **));
    for (i = 0; i < nthreads; i++) {
        if (i == 0)
            temp[i] = partial_new_centers[0];
        else
            temp[i] = temp[i - 1] + nclusters;
    }
    // Copy results back in order to preserve original semantics
    for (i = 1; i < nthreads; i++) {
        partial_new_centers[i] = temp[i];
    }
    free(temp);
}
