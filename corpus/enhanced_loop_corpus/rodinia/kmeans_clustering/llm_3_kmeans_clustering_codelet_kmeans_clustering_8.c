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
    // Variant 2: Memory Access Pattern Modification - Consecutive Flat Array Access via Pointer Arithmetic
    // Treat 2D arrays as consecutive memory blocks for more cache-friendly linear traversal
    float *clusters_ptr = &clusters[0][0];
    float *new_centers_ptr = &new_centers[0][0];
    int total_elements = nclusters * nfeatures;

    for (int idx = 0; idx < total_elements; idx++) {
        int i = idx / nfeatures;  // Recover cluster index
        int j = idx % nfeatures;  // Recover feature index

        if (j == 0 && i > 0) {
            new_centers_len[i-1] = 0;  // Finalize previous cluster's length (shifted due to post-update)
        }

        if (new_centers_len[i] > 0) {
            clusters_ptr[idx] = new_centers_ptr[idx] / new_centers_len[i];
        }
        new_centers_ptr[idx] = 0.0f;

        // Finalize last cluster after loop
        if (i == nclusters - 1 && j == nfeatures - 1) {
            new_centers_len[i] = 0;
        }
    }
}
