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
if (K <= 0 || N == 0) return;
const int stride = (incX > 0 ? incX : -incX);
for (i = 0; i < N; i += 2) {
    const int i1 = i;
    const int i2 = i + 1;
    double temp1 = (nonunit ? A[lda * i1 + 0] : 1.) * X[ix];
    double temp2 = (i2 < N && nonunit) ? A[lda * i2 + 0] : 1.;
    temp2 *= (i2 < N) ? X[ix + ((incX > 0) ? stride : -stride * (N-1))] : 0.;

    const int j_min = i1 + 1;
    const int j_max = ((N) < (i1 + K + 1) ? (N) : (i1 + K + 1));

    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;

    for (j = j_min; j < j_max; j++) {
        temp1 += X[jx] * A[lda * i1 + (j - i1)];
        if (i2 < N && j >= i2 + 1) {
            temp2 += X[jx] * A[lda * i2 + (j - i2)];
        }
        jx += incX;
    }

    X[ix] = temp1;
    ix += incX;

    if (i2 < N) {
        int ix2 = ix + ((incX > 0) ? stride : -stride * (N-1));
        X[ix2] = temp2;
    }
}
}
