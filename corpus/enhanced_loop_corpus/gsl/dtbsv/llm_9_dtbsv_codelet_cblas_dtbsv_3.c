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
if (K <= 0 || N <= 0) return;
const int unroll_factor = 2;
int bound = N - (N % unroll_factor);
for (i = bound; i > 0; i -= unroll_factor) {
    double tmp0 = X[ix];
    double tmp1 = X[ix - incX];
    const int j_min0 = i;
    const int j_max0 = (N < i + K) ? N : (i + K);
    const int j_min1 = i - 1;
    const int j_max1 = (N < i + K) ? N : (i + K);
    int jx0 = (incX > 0 ? 0 : (N - 1) * (-incX)) + j_min0 * incX;
    int jx1 = (incX > 0 ? 0 : (N - 1) * (-incX)) + j_min1 * incX;

    for (j = (i == N ? i : j_min0); j < j_max0; j++) {
        const double Aji0 = A[(K + i - 1 - j) + lda * j];
        const double Aji1 = A[(K + i - 2 - j) + lda * j];
        tmp0 -= Aji0 * X[jx0];
        tmp1 -= Aji1 * X[jx1];
        jx0 += incX;
        jx1 += incX;
    }

    if (nonunit) {
        X[ix] = tmp0 / A[K + lda * (i - 1)];
        X[ix - incX] = tmp1 / A[K + lda * (i - 2)];
    } else {
        X[ix] = tmp0;
        X[ix - incX] = tmp1;
    }
    ix -= 2 * incX;
}

for (; i > 0; i--) {
    double tmp = X[ix];
    const int j_min = i;
    const int j_max = (N < i + K) ? N : (i + K);
    int jx = (incX > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const double Aji = A[(K + i - 1 - j) + lda * j];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[K + lda * (i - 1)];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
