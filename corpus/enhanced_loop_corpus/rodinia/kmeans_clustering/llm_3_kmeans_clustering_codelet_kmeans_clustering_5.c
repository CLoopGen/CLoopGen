#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern int j;
extern int *new_centers_len;
extern float **clusters;
extern float **new_centers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *centers_base = (float*)malloc(nclusters * nfeatures * sizeof(float));
float *new_centers_flat = (float*)malloc(nclusters * nfeatures * sizeof(float));

// Flatten and reorganize access: convert 2D indirect to 1D strided access
for (i = 0; i < nclusters; i++) {
    for (j = 0; j < nfeatures; j++) {
        int idx = i * nfeatures + j;
        if (new_centers_len[i] > 0)
            centers_base[idx] = new_centers_flat[idx] / new_centers_len[i];
        new_centers_flat[idx] = 0.0f;
    }
    new_centers_len[i] = 0;
}

// Copy back to original structure (assuming clusters and new_centers are still used afterward)
for (i = 0; i < nclusters; i++) {
    for (j = 0; j < nfeatures; j++) {
        int idx = i * nfeatures + j;
        clusters[i][j] = centers_base[idx];
        new_centers[i][j] = new_centers_flat[idx];
    }
}

free(centers_base);
free(new_centers_flat);
}
