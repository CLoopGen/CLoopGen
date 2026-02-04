#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
for (i = 0; i < N; i++) {
    const double tmp = alpha * X[ix];
    int jx = ix;
    for (j = i; j < N && j < i + 4; j++) { // Unroll-like limited inner loop
        Ap[((i * (2 * N - i + 1)) / 2) + (j - i)] += X[jx] * tmp;
        jx += incX;
    }
    // Remaining iterations processed with reduced frequency
    for (j = i + 4; j < N; j += 2) {
        jx = ix + (j - i) * incX;
        Ap[((i * (2 * N - i + 1)) / 2) + (j - i)] += X[jx] * tmp;
    }
    ix += incX;
}
}
