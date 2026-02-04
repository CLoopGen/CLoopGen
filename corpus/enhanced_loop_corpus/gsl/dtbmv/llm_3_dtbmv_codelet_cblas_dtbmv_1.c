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
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N; i > 0 && i--;) {
    double temp = (nonunit ? A[lda * i + K] : 1.) * X[ix];
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    // Use strided access with direct index scaling instead of jx variable
    int x_base_offset = ((incX) > 0 ? 0 : (N - 1) * (-incX));
    for (j = j_min; j < j_max; j++) {
        int x_index = x_base_offset + j * incX;
        int a_index = lda * i + (K - i + j);
        temp += X[x_index] * A[a_index];
    }
    X[ix] = temp;
    ix -= incX;
}
}
