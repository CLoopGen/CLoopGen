#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

float imc_exp_tab[32];
int *levlCoeffBuf;
float *flcoeffs1;
float *flcoeffs2;
int i;
int level;
float tmp;
float tmp2;

void init_vars() {
    // Allocate buffers with sufficient size to avoid out-of-bounds access
    levlCoeffBuf = (int*)malloc(32 * sizeof(int));
    flcoeffs1 = (float*)malloc(32 * sizeof(float));
    flcoeffs2 = (float*)malloc(32 * sizeof(float));

    // Initialize imc_exp_tab using expf-like values to avoid undefined expf reference
    // Since we cannot call expf, we precompute or use a simple replacement
    // Using a fixed pattern to simulate reasonable values
    for (int idx = 0; idx < 32; idx++) {
        imc_exp_tab[idx] = 1.0f + (idx * 0.1f); // Dummy initialization to avoid expf
    }

    // Initialize levlCoeffBuf with sample data that triggers all branches
    for (int idx = 1; idx < 32; idx++) {
        if (idx == 16) {
            levlCoeffBuf[idx] = 16;
        } else if (idx < 17) {
            levlCoeffBuf[idx] = 10; // < 17 -> subtract 7
        } else if (idx <= 24) {
            levlCoeffBuf[idx] = 20; // <= 24 -> subtract 32
        } else {
            levlCoeffBuf[idx] = 30; // > 24 -> subtract 16
        }
    }

    // Initialize loop-carried variables
    tmp = 1.0f;
    tmp2 = 0.0f;

    // Initialize output arrays to safe values
    for (int idx = 0; idx < 32; idx++) {
        flcoeffs1[idx] = 0.0f;
        flcoeffs2[idx] = 0.0f;
    }
}