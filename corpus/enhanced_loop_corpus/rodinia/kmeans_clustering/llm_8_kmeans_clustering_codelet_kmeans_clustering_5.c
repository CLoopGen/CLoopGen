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
for (i = 0; i < nclusters; i += 2) {
    if (i + 1 < nclusters) {
        for (j = 0; j < nfeatures; j++) {
            if (new_centers_len[i] > 0)
                clusters[i][j] = new_centers[i][j] / new_centers_len[i];
            else
                clusters[i][j] = 0.0;
            new_centers[i][j] = 0.;

            if (new_centers_len[i+1] > 0)
                clusters[i+1][j] = new_centers[i+1][j] / new_centers_len[i+1];
            else
                clusters[i+1][j] = 0.0;
            new_centers[i+1][j] = 0.;
        }
        new_centers_len[i] = 0;
        new_centers_len[i+1] = 0;
    } else {
        for (j = 0; j < nfeatures; j++) {
            if (new_centers_len[i] > 0)
                clusters[i][j] = new_centers[i][j] / new_centers_len[i];
            else
                clusters[i][j] = 0.0;
            new_centers[i][j] = 0.;
        }
        new_centers_len[i] = 0;
    }
}
}
