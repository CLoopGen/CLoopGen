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
for (i = 1; i < N; i++) {
    double tmp1 = X[ix];
    double tmp2 = 0.0;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i - 1; j += 2) {
        const double Aij1 = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        const double Aij2 = Ap[(((i) * ((i) + 1)) / 2 + (j + 1))];
        tmp1 -= Aij1 * X[jx];
        tmp2 -= Aij2 * X[jx + incX];
        jx += 2 * incX;
    }
    if (j < i) {
        const double Aij = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        tmp1 -= Aij * X[jx];
        jx += incX;
    }
    tmp1 += tmp2;
    if (nonunit) {
        X[ix] = tmp1 / Ap[(((i) * ((i) + 1)) / 2 + (j))];
    } else {
        X[ix] = tmp1;
    }
    ix += incX;
}
}
