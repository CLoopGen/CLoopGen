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
for (i = N - 1; i > 0 && i--;) {
    double tmp = X[ix];
    int jx = ix + incX;
    // Change memory access to use a precomputed base index for Ap to enable consecutive-like access via offset array
    int base_Ap_idx = ((i) * ((i) + 1)) / 2;
    for (j = i + 1; j < N; j++) {
        const double Aji = Ap[base_Ap_idx + j];  // Now accessing Ap with linear offset from base
        tmp -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / Ap[base_Ap_idx + i];  // Reuse computed base index
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
