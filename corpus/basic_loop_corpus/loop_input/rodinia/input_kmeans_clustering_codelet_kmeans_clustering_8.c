#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nfeatures;
int nclusters;
int i;
int j;
int *new_centers_len;
float **new_centers;
float **clusters;

void init_vars() {
    nclusters = 1024;
    nfeatures = 256;

    new_centers_len = (int*)calloc(nclusters, sizeof(int));
    
    clusters = (float**)malloc(nclusters * sizeof(float*));
    new_centers = (float**)malloc(nclusters * sizeof(float*));
    
    for (int idx = 0; idx < nclusters; idx++) {
        clusters[idx] = (float*)malloc(nfeatures * sizeof(float));
        new_centers[idx] = (float*)malloc(nfeatures * sizeof(float));
        
        new_centers_len[idx] = rand() % 100 + 1;
        
        for (int jdx = 0; jdx < nfeatures; jdx++) {
            new_centers[idx][jdx] = (float)(rand() % 1000) / 10.0f;
            clusters[idx][jdx] = 0.0f;
        }
    }
}