#include <stdio.h>
#include <stdlib.h>

double ***z;
int m0;
int i;
int j1[10][2];
int j2[10][2];
int j3[10][2];

void init_vars() {
    // Set loop boundary so that loop runs 10 iterations (i from 9 down to 0)
    m0 = 0;

    // Initialize index arrays to valid values
    for (int idx = 0; idx < 10; idx++) {
        j1[idx][0] = 0;
        j2[idx][0] = 0;
        j3[idx][0] = idx;  // ensure spread across first dimension
        j1[idx][1] = 0;
        j2[idx][1] = 0;
        j3[idx][1] = 0;
    }

    // Allocate z[j3][j2][j1] with sufficient size to prevent out-of-bounds
    // We need at least max(j3[i][0])+1 = 10 blocks in first dimension
    z = (double***)calloc(10, sizeof(double**));
    for (int i = 0; i < 10; i++) {
        z[i] = (double**)calloc(1, sizeof(double*));  // j2[i][0] is always 0
        z[i][0] = (double*)calloc(1, sizeof(double)); // j1[i][0] is always 0
    }

    // Ensure total data size is large enough to make loop take ~0.01s
    // But since loop only writes 10 times, we don't need huge data
    // However, to meet timing via memory footprint, expand one block
    free(z[0][0]);
    z[0][0] = (double*)calloc(1 << 20, sizeof(double)); // ~8MB per double block

    // Reinitialize to avoid accidental out-of-bound usage
    for (int idx = 0; idx < 10; idx++) {
        j1[idx][0] = 0;
        j2[idx][0] = 0;
        j3[idx][0] = (idx < 1) ? 0 : idx; // mostly use z[0][0][0]
    }
}