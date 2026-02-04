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
double *restrict local_X = X;
const double *restrict local_A = A;
#pragma GCC ivdep
for (i = N; i > 0; --i) {
    const int ii = i - 1;
    double tmp = local_X[ix];
    const int j_min = ii + 1;
    const int j_max = ((N) < (ii + K + 1) ? (N) : (ii + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const int a_index = (K + ii - j) + lda * j;
        const double Aji = local_A[a_index];
        tmp -= Aji * local_X[jx];
        jx += incX;
    }
    if (nonunit) {
        const int diag_index = K + lda * ii;
        tmp /= local_A[diag_index];
    }
    local_X[ix] = tmp;
    ix -= incX;
}
}
