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
    // Variant 2: Indirect (gather-scatter) memory access using index arrays
    // This variant replaces direct indexing with indirect access via precomputed index vectors
    // Simulates scenarios where access patterns are irregular or data-dependent.

    int *ap_indices = (int*)malloc((N * (N + 1)) / 2 * sizeof(int));
    int *x_indices = (int*)malloc(N * sizeof(int));

    // Precompute all needed Ap indices (lower triangular part stored column-wise)
    int idx = 0;
    for (int col = 0; col < N; col++) {
        for (int row = 0; row <= col; row++) {
            ap_indices[col * (col + 1) / 2 + row] = idx++;
        }
    }

    // Precompute X indices based on initial ix and incX
    int current_ix = ix;
    for (int k = 0; k < N; k++) {
        x_indices[k] = current_ix;
        current_ix -= incX;
    }

    // Main loop using indirect addressing
    for (i = N; i > 0 && i--;) {
        int ap_diag_idx = ((i) * ((i) + 1)) / 2 + (i);
        double atmp = Ap[ap_indices[ap_diag_idx]];
        double temp = (nonunit ? X[x_indices[i]] * atmp : X[x_indices[i]]);

        int jx_idx = (incX > 0 ? 0 : N - 1);
        for (j = 0; j < i; j++) {
            int ap_access_idx = ((i) * ((i) + 1)) / 2 + (j);
            atmp = Ap[ap_indices[ap_access_idx]];
            temp += atmp * X[x_indices[j]];
            jx_idx += (incX > 0 ? 1 : -1);
        }
        X[x_indices[i]] = temp;
    }

    free(ap_indices);
    free(x_indices);
}
