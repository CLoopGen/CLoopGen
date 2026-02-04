#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nclusters = 1024;
int i;
int nthreads = 8;

float ***partial_new_centers;

void init_vars() {
    partial_new_centers = (float ***)calloc(nthreads, sizeof(float **));
    if (!partial_new_centers) exit(1);

    for (int tid = 0; tid < nthreads; tid++) {
        partial_new_centers[tid] = (float **)calloc(nclusters, sizeof(float *));
        if (!partial_new_centers[tid]) exit(1);
        for (int c = 0; c < nclusters; c++) {
            partial_new_centers[tid][c] = (float *)calloc(32, sizeof(float));
            if (!partial_new_centers[tid][c]) exit(1);
        }
    }

    for (i = 1; i < nthreads; i++)
        partial_new_centers[i] = partial_new_centers[i - 1] + nclusters;
}