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
    // Variant 1: Consecutive Memory Access Pattern
    // Modify access to X by precomputing a consecutive array slice to enable sequential access.
    // We assume X is accessed with stride `incX`, so we create a local view with unit stride.
    double *X_seq = (double*)malloc(N * sizeof(double));
    for (int k = 0; k < N; k++) {
        X_seq[k] = X[k * incX];
    }
    int offset = (N - 1) * incX;

    for (i = N - 1; i > 0 && i--;) {
        double tmp = X_seq[i];
        for (j = i + 1; j < N; j++) {
            const double Aij = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
            tmp -= Aij * X_seq[j];
        }
        if (nonunit) {
            X_seq[i] = tmp / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
        } else {
            X_seq[i] = tmp;
        }
    }

    // Write back to original strided memory layout
    for (int k = 0; k < N; k++) {
        X[k * incX] = X_seq[k];
    }
    free(X_seq);
    ix = offset; // restore expected state of ix
}
