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
double *x_base = X;
const ptrdiff_t stride = incX;
for (i = 1; i < N; i++) {
    double tmp = x_base[ix];
    int k = 0;
    for (j = 0; j < i; j++) {
        const double Aij = Ap[(i*(i+1))/2 + j];
        tmp -= Aij * x_base[k * stride];
        k++;
    }
    if (nonunit) {
        X[ix] = tmp / Ap[(i*(i+1))/2 + i];
    } else {
        X[ix] = tmp;
    }
    ix += stride;
}
}
