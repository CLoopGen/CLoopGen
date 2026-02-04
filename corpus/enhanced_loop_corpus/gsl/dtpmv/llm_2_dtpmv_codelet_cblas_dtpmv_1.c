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
    // Variant 1: Consecutive memory access by precomputing and storing indices for Ap and X
    // This variant restructures the inner loop to access Ap in a forward, consecutive manner
    // and uses a temporary array to allow sequential X access, improving cache locality.

    double *X_temp = (double*)malloc(N * sizeof(double));
    for (int k = 0; k < N; k++) {
        X_temp[k] = X[ix + k * incX];  // Flatten X into consecutive array
    }

    for (i = N - 1; i >= 0; i--) {
        int base_idx = (i * (i + 1)) / 2 + i;
        double atmp = Ap[base_idx];
        double temp = (nonunit ? X_temp[i] * atmp : X_temp[i]);

        int j_start = (incX > 0 ? 0 : N - 1) * (incX < 0 ? -1 : 0);
        int jx = j_start;
        for (j = 0; j < i; j++) {
            int ap_idx = base_idx - (i - j);  // Access Ap backwards but consecutively from base
            atmp = Ap[ap_idx];
            temp += atmp * X_temp[j];
            jx += incX;
        }
        X_temp[i] = temp;
    }

    // Write back to original strided X
    int write_ix = ix;
    for (int k = 0; k < N; k++) {
        X[write_ix] = X_temp[N - 1 - k];
        write_ix -= incX;
    }

    free(X_temp);
}
