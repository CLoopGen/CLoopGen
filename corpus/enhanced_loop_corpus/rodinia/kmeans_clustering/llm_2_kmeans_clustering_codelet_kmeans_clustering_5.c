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
for (i = 0; i < nclusters; i++) {
    if (new_centers_len[i] > 0) {
        float inv_len = 1.0f / new_centers_len[i];
        for (j = 0; j < nfeatures; j++) {
            clusters[i][j] = new_centers[i][j] * inv_len;
            new_centers[i][j] = 0.0f;
        }
    } else {
        for (j = 0; j < nfeatures; j++) {
            clusters[i][j] = 0.0f;
            new_centers[i][j] = 0.0f;
        }
    }
    new_centers_len[i] = 0;
}
}
