#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 1) return;
double temp_storage[N]; 
for (int k = 0; k < N; k++) temp_storage[k] = 0.0;

for (i = 1; i < N; i++) {
    double tmp = X[ix];
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j++) {
        const double Aji = A[lda * j + i];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    temp_storage[i] = nonunit ? tmp / A[lda * i + i] : tmp;
}
ix = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
for (i = 1; i < N; i++) {
    ix += incX;
    X[ix] = temp_storage[i];
}
}
