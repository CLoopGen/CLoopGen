#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to use consecutive indexing with precomputed offsets
    // Instead of recalculating Ap index using triangular formula each time, precompute base indices in a strided manner
    int *index_map = (int*)malloc(N * sizeof(int));
    for (int k = 0; k < N; ++k) {
        index_map[k] = (k * (k + 1)) / 2 + k;
    }
    int ix_save = ix;
    int incX_abs = (incX > 0 ? incX : -incX);
    int jx_base = (incX > 0 ? 0 : (N - 1) * (-incX));

    for (i = 0; i < N; i++) {
        double atmp = Ap[index_map[i]];
        double temp = (nonunit ? X[ix] * atmp : X[ix]);
        int jx = jx_base + (i + 1) * incX;
        for (j = i + 1; j < N; j++) {
            atmp = Ap[index_map[j] + i];  // Lower triangular part accessed via precomputed diagonal base + offset
            temp += atmp * X[jx];
            jx += incX;
        }
        X[ix] = temp;
        ix += incX;
    }
    free(index_map);
}
