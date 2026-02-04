#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nfeatures;
int npoints;
float **features;
int i;

void init_vars() {
    npoints = 1 << 20; // Approximately 1M points for ~0.01 sec runtime
    nfeatures = 64;    // 64 features per point

    features = (float**)calloc(npoints, sizeof(float*));
    if (!features) exit(1);

    for (int idx = 0; idx < npoints; idx++) {
        features[idx] = (float*)calloc(nfeatures, sizeof(float));
        if (!features[idx]) exit(1);
    }
}