#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **feature;
int nfeatures = 1024;
int nclusters = 50;
int i;
int j;
int n = 0;
int temp;
float **clusters;
int *initial;
int initial_points;

void init_vars() {
    // Allocate feature array
    feature = (float**)calloc(nfeatures, sizeof(float*));
    for (int idx = 0; idx < nfeatures; idx++) {
        feature[idx] = (float*)calloc(nfeatures, sizeof(float));
        for (int jdx = 0; jdx < nfeatures; jdx++) {
            feature[idx][jdx] = (float)(rand()) / RAND_MAX * 100.0f;
        }
    }

    // Set initial_points to nclusters to match loop condition
    initial_points = nclusters;

    // Allocate and initialize initial array
    initial = (int*)malloc(initial_points * sizeof(int));
    for (int idx = 0; idx < initial_points; idx++) {
        initial[idx] = idx % nfeatures;
    }

    // Allocate clusters
    clusters = (float**)calloc(nclusters, sizeof(float*));
    for (int idx = 0; idx < nclusters; idx++) {
        clusters[idx] = (float*)calloc(nfeatures, sizeof(float));
    }

    // Reset n to 0 as it's used in loop
    n = 0;
}