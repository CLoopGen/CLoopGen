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
    int has_data = new_centers_len[i] > 0;
    for (j = 0; j < nfeatures; j++) {
        if (has_data)
            clusters[i][j] = new_centers[i][j] * (1.0f / new_centers_len[i]);
        else
            clusters[i][j] = 0.;
        new_centers[i][j] = 0.;
    }
    new_centers_len[i] = 0;
}
}
