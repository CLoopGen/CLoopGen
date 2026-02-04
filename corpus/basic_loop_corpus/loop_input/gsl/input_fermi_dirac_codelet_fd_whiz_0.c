#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int iterm;
double *qnum;
double *qden;
double factor;
double ratio;
int j;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Empirical testing suggests iterm around 200k - 500k gives desired timing
    iterm = 300000;

    // Allocate arrays with extra element to avoid out-of-bounds access
    qnum = (double*)aligned_alloc(32, (iterm + 2) * sizeof(double));
    qden = (double*)aligned_alloc(32, (iterm + 2) * sizeof(double));

    // Initialize array elements to prevent NaN/inf issues
    for (int i = 0; i <= iterm + 1; i++) {
        qnum[i] = 1.0 + i * 0.001;
        qden[i] = 1.0 + i * 0.002;
    }

    // Initialize scalar variables
    factor = 1.5;
    ratio = 0.999;
    j = 0;
}