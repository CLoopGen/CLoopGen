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
    // Unroll the inner loop by a factor of 2 to reduce loop overhead and increase computational intensity
    for (j = i + 1; j < N - 1; j += 2) {
        const double Aij1 = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        const double Aij2 = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j + 1) - (i))];
        tmp -= Aij1 * X[jx] + Aij2 * X[jx + incX];
        jx += 2 * incX;
    }
    // Handle remaining element if N - i - 1 is odd
    if (j == N - 1) {
        const double Aij = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        tmp -= Aij * X[jx];
    }
    if (nonunit) {
        X[ix] = tmp / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
