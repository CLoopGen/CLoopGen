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
for (i = 0; i < nclusters; i += 2) {
    int i1 = i;
    int i2 = i + 1;
    for (j = 0; j < nfeatures; j++) {
        if (i1 < nclusters && new_centers_len[i1] > 0)
            clusters[i1][j] = new_centers[i1][j] / new_centers_len[i1];
        new_centers[i1][j] = 0.0f;

        if (i2 < nclusters) {
            if (new_centers_len[i2] > 0)
                clusters[i2][j] = new_centers[i2][j] / new_centers_len[i2];
            new_centers[i2][j] = 0.0f;
        }
    }
    new_centers_len[i1] = 0;
    if (i2 < nclusters)
        new_centers_len[i2] = 0;
}
}
