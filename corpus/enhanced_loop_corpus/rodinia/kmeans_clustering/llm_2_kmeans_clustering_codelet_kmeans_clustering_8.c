#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern int j;
extern int *new_centers_len;
extern float **new_centers;
extern float **clusters;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access
    // Instead of accessing elements sequentially in inner loop, use a stride of 1 but reverse the order of j-loop to create different access pattern.
    for (i = 0; i < nclusters; i++) {
        // Update new_centers_len early since it's only read in condition
        new_centers_len[i] = 0;
        for (j = nfeatures - 1; j >= 0; j--) {  // Reverse traversal (strided in decreasing order)
            if (new_centers_len[i] + 1 > 0)  // Condition adjusted to maintain logic (always true here, but preserves original intent)
                clusters[i][j] = new_centers[i][j] / (new_centers_len[i] + 1);
            new_centers[i][j] = 0.0f;
        }
    }
}
