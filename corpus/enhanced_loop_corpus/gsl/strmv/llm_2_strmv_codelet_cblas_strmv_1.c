#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N; i > 0 && i--;) {
    float temp = 0.;
    const int j_min = 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    // Change to consecutive memory access by precomputing base pointer for X
    float *X_base = &X[jx];
    for (j = j_min; j < j_max; j++) {
        temp += X_base[j * (incX == 1 ? 1 : 1)] * A[lda * i + j]; // Ensure unit stride when incX allows
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
}
}
