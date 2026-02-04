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
for (i = 0; i < nclusters; i++) {
    if (new_centers_len[i] > 0) {
        for (j = 0; j < nfeatures; j++) {
            clusters[i][j] = (new_centers[i][j] + 1.0f) / (new_centers_len[i] + 1);
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
