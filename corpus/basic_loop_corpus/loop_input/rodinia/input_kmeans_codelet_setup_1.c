#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nfeatures;
int npoints;
float **features;
int i;

void init_vars() {
    nfeatures = 256;
    npoints = 100000;

    features = (float**)calloc(npoints, sizeof(float*));
    if (!features) exit(1);

    for (int idx = 0; idx < npoints; idx++) {
        features[idx] = (float*)malloc(nfeatures * sizeof(float));
        if (!features[idx]) exit(1);
    }
}