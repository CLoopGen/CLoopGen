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
if (N <= 0) return;
int stride = (K + 1) > 8 ? 8 : (K + 1);
for (i = 0; i < N; i += stride) {
    int end_i = (i + stride < N) ? i + stride : N;
    for (int ii = i; ii < end_i; ii++) {
        double tmp = X[ix];
        const int j_min = (K > ii ? 0 : ii - K);
        const int j_max = ii;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            const double Aji = A[(ii - j) + lda * j];
            tmp -= Aji * X[jx];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = tmp / A[0 + lda * ii];
        } else {
            X[ix] = tmp;
        }
        ix += incX;
    }
}
}
