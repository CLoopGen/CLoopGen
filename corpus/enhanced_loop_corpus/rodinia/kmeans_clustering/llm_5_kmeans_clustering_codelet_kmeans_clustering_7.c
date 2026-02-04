#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern int j;
extern int k;
extern int *new_centers_len;
extern float **new_centers;
extern int nthreads;
extern int **partial_new_centers_len;
extern float ***partial_new_centers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nclusters; i++) {
    int total_len = 0;
    for (j = 0; j < nthreads; j++) {
        total_len += partial_new_centers_len[j][i];
    }
    if (total_len > 0) {
        new_centers_len[i] += total_len;
        for (j = 0; j < nthreads; j++) {
            partial_new_centers_len[j][i] = 0;
            for (k = 0; k < nfeatures; k++) {
                new_centers[i][k] += partial_new_centers[j][i][k];
                partial_new_centers[j][i][k] = 0.0;
            }
        }
    }
}
}
