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
    double temp1 = 0.0, temp2 = 0.0;
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    
    if (nonunit) {
        temp1 = A[lda * i + K] * X[ix];
    } else {
        temp1 = X[ix];
    }

    for (j = j_min; j < j_max; j += 2) {
        if (j + 1 < j_max) {
            temp1 += X[jx] * A[lda * i + (K - i + j)];
            jx += incX;
            temp2 += X[jx] * A[lda * i + (K - i + j + 1)];
            jx += incX;
        } else {
            temp1 += X[jx] * A[lda * i + (K - i + j)];
            jx += incX;
        }
    }
    X[ix] = temp1 + temp2;
    ix -= incX;
}
}
