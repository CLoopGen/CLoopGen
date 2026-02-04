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
for (i = 1; i < N; i += 2) {
    double tmp1 = X[ix];
    double tmp2 = (i + 1 < N) ? X[ix + incX] : 0.0;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j++) {
        const double Aji = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
        tmp1 -= Aji * X[jx];
        if (i + 1 < N && j < i + 1) {
            const double Ajip1 = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i + 1) - (j))];
            tmp2 -= Ajip1 * X[jx];
        }
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp1 / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
        if (i + 1 < N) {
            X[ix + incX] = tmp2 / Ap[((((((i+1) - 1) + 1) * (2 * (N) - ((i+1) - 1))) / 2) + (i+1) - (i+1))];
        }
    } else {
        X[ix] = tmp1;
        if (i + 1 < N) {
            X[ix + incX] = tmp2;
        }
    }
    ix += 2 * incX;
    i++; // Adjust to account for +=2 in for-loop
}
}
