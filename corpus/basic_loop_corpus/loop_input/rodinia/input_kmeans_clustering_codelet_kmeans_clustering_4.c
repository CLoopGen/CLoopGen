#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nfeatures = 1024;
int nclusters = 65536;
int i;
float **new_centers;

void init_vars() {
    new_centers = (float**)calloc(nclusters, sizeof(float*));
    if (!new_centers) {
        exit(1);
    }
    for (int idx = 0; idx < nclusters; idx++) {
        new_centers[idx] = (float*)calloc(nfeatures, sizeof(float));
        if (!new_centers[idx]) {
            exit(1);
        }
    }
}