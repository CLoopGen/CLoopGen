#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nfeatures;
int nclusters;
int i;
int j;
int *new_centers_len;
float **clusters;
float **new_centers;

void init_vars() {
    nclusters = 1000;
    nfeatures = 500;

    new_centers_len = (int*)calloc(nclusters, sizeof(int));

    clusters = (float**)malloc(nclusters * sizeof(float*));
    new_centers = (float**)malloc(nclusters * sizeof(float*));

    for (int idx = 0; idx < nclusters; idx++) {
        clusters[idx] = (float*)malloc(nfeatures * sizeof(float));
        new_centers[idx] = (float*)malloc(nfeatures * sizeof(float));
        new_centers_len[idx] = (idx % 7) + 1;

        for (int jdx = 0; jdx < nfeatures; jdx++) {
            new_centers[idx][jdx] = (float)(idx + jdx);
            clusters[idx][jdx] = 0.0f;
        }
    }
}