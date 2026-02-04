#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nfeatures = 1024;
int nclusters = 65536;
int i;
float **clusters;

void init_vars() {
    clusters = (float**)calloc(nclusters, sizeof(float*));
    if (!clusters) {
        exit(1);
    }
    float *data_block = (float*)calloc(nclusters * nfeatures, sizeof(float));
    if (!data_block) {
        exit(1);
    }
    for (int idx = 0; idx < nclusters; idx++) {
        clusters[idx] = data_block + idx * nfeatures;
    }
}