#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

float *flcoeffs1;
float *flcoeffs2;
int *bandWidthT;
float *flcoeffs3;
float *flcoeffs5;
float workT1[32];
float workT2[32];
float workT3[32];
float snr_limit;
int i;

void init_vars() {
    flcoeffs1 = (float*)aligned_alloc(32, 32 * sizeof(float));
    flcoeffs2 = (float*)aligned_alloc(32, 32 * sizeof(float));
    bandWidthT = (int*)aligned_alloc(32, 32 * sizeof(int));
    flcoeffs3 = (float*)aligned_alloc(32, 32 * sizeof(float));
    flcoeffs5 = (float*)aligned_alloc(32, 32 * sizeof(float));

    for (int j = 0; j < 32; j++) {
        flcoeffs1[j] = 1.0f + j * 0.1f;
        flcoeffs2[j] = 2.0f + j * 0.2f;
        bandWidthT[j] = (j % 3) ? 1 : 0;
    }

    snr_limit = 0.05f;
}