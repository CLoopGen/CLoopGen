#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *ac;
int lag;
int n;
int fastN;
float *xptr;

void init_vars() {
    // Set parameters to control data size and loop behavior
    lag = 1000;
    fastN = 100;
    n = 200000;  // Ensures sufficient size for meaningful computation

    // Allocate arrays with appropriate sizes to prevent out-of-bounds access
    ac = (float*)calloc(lag + 1, sizeof(float));
    xptr = (float*)malloc(n * sizeof(float));

    // Initialize xptr with non-zero values to make accumulation meaningful
    for (int i = 0; i < n; i++) {
        xptr[i] = (float)((rand() % 1000) / 100.0);
    }
}