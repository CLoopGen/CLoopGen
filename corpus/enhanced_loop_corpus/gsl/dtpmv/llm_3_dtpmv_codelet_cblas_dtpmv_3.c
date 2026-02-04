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
    // Variant 2: Use indirect (gather/scatter) access via pointer arrays to simulate irregular memory access
    // Create pointer array to simulate indirect access to Ap and X, improving cache behavior in some scenarios

    // Precompute pointers to Ap rows based on lower triangular layout
    double **Ap_ptr = (double**)malloc(N * sizeof(double*));
    for (int k = 0; k < N; ++k) {
        Ap_ptr[k] = &Ap[(k * (k + 1)) / 2];  // Each row starts here; column i is at offset i
    }

    int start_jx = (incX > 0 ? 0 : (N - 1) * (-incX));
    int *X_index = (int*)malloc(N * sizeof(int));  // Indirect indexing for X
    for (int k = 0; k < N; ++k) {
        X_index[k] = start_jx + k * incX;
    }

    for (i = 0; i < N; i++) {
        double atmp = Ap_ptr[i][i];
        double temp = (nonunit ? X[ix] * atmp : X[ix]);
        for (j = i + 1; j < N; j++) {
            atmp = Ap_ptr[j][i];  // Access Ap[j][i] indirectly through precomputed row pointers
            temp += atmp * X[X_index[j]];  // Gather X values via indirect index
        }
        X[ix] = temp;
        ix += incX;
    }

    free(Ap_ptr);
    free(X_index);
}
