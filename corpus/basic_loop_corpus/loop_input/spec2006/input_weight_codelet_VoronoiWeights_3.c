#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <math.h>

int nseq;
float *wgt;
int idx;
int itscale;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume modern CPU can do ~1e9 operations/sec -> target ~1e7 operations
    // Each loop iteration does one division -> aim for 10M elements

    nseq = 10000000;  // 10 million elements
    itscale = 4;      // arbitrary non-zero scale factor

    // Allocate wgt array
    wgt = (float*)malloc(nseq * sizeof(float));
    if (!wgt) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize wgt with non-zero values to make division meaningful
    for (int i = 0; i < nseq; i++) {
        wgt[i] = (float)(i % 1000) + 1.0f;
    }
}