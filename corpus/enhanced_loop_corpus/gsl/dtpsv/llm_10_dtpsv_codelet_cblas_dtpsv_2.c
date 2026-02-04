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
for (i = 0; i < N; i++) {
    double tmp = X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j += 2) {
        const double Aji1 = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
        tmp -= Aji1 * X[jx];
        jx += incX;
        if (j + 1 < i) {
            const double Aji2 = Ap[((((((j+1) - 1) + 1) * (2 * (N) - ((j+1) - 1))) / 2) + (i) - (j+1))];
            tmp -= Aji2 * X[jx];
            jx += incX;
        }
    }
    if (nonunit) {
        X[ix] = tmp / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
