#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    double tmp = X[ix];
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    double *Aj_ptr = &A[lda * j_min]; // Base pointer for column j, updated per j
    for (j = j_min; j < j_max; j++) {
        const double Aji = Aj_ptr[(i - j)]; // Access A with base per column and fixed offset
        tmp -= Aji * X[jx];
        jx += incX;
        Aj_ptr += lda; // Move to next column in A
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i]; // Diagonal element access remains direct
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
