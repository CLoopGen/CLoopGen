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
double *X_start = X;
int ix_start = ix;
for (i = 0; i < N; i++) {
    double tmp = X[ix];
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    for (j = j_min; j < j_max; j += 2) {
        const double Aji1 = A[(i - j) + lda * j];
        tmp -= Aji1 * X[jx];
        jx += incX;
        if (j + 1 < j_max) {
            const double Aji2 = A[(i - (j + 1)) + lda * (j + 1)];
            tmp -= Aji2 * X[jx];
            jx += incX;
        }
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
