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
    int len = new_centers_len[i];
    float inv_len = (len > 0) ? 1.0f / len : 0.0f;
    for (j = 0; j < nfeatures; j++) {
        float temp = new_centers[i][j] * inv_len;
        clusters[i][j] = temp;
        new_centers[i][j] = 0.0f;
    }
    new_centers_len[i] = 0;
}
}
