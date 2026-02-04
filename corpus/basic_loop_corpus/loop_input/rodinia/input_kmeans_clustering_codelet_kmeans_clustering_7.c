#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nfeatures = 128;
int nclusters = 64;
int i, j, k;
int nthreads = 8;

int *new_centers_len;

float **new_centers;

int **partial_new_centers_len;
float ***partial_new_centers;

void init_vars() {
    // Allocate and initialize new_centers_len
    new_centers_len = (int*)calloc(nclusters, sizeof(int));
    for (i = 0; i < nclusters; i++) {
        new_centers_len[i] = 0;
    }

    // Allocate and initialize new_centers
    new_centers = (float**)malloc(nclusters * sizeof(float*));
    for (i = 0; i < nclusters; i++) {
        new_centers[i] = (float*)calloc(nfeatures, sizeof(float));
        for (j = 0; j < nfeatures; j++) {
            new_centers[i][j] = 0.0f;
        }
    }

    // Allocate and initialize partial_new_centers_len and partial_new_centers
    partial_new_centers_len = (int**)malloc(nthreads * sizeof(int*));
    partial_new_centers = (float***)malloc(nthreads * sizeof(float**));

    for (j = 0; j < nthreads; j++) {
        partial_new_centers_len[j] = (int*)malloc(nclusters * sizeof(int));
        partial_new_centers[j] = (float**)malloc(nclusters * sizeof(float*));

        for (i = 0; i < nclusters; i++) {
            partial_new_centers_len[j][i] = 1; // Simulate non-zero count for accumulation
            partial_new_centers[j][i] = (float*)malloc(nfeatures * sizeof(float));
            for (k = 0; k < nfeatures; k++) {
                partial_new_centers[j][i][k] = 1.0f / (nthreads * nclusters); // Small values to accumulate
            }
        }
    }
}