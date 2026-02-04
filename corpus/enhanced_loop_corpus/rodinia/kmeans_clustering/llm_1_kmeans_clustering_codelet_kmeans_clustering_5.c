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
    for (j = 0; j < nfeatures; j++) {
        float *cluster_row = clusters[i];
        float *new_center_row = new_centers[i];
        int len = new_centers_len[i];
        if (len > 0)
            cluster_row[j] = new_center_row[j] / len;
        new_center_row[j] = 0.;
    }
    new_centers_len[i] = 0;
}
}
