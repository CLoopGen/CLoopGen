#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    double tmp1 = alpha * X[ix];
    double tmp2 = 0.;
    Y[iy] += tmp1 * A[0 + i * lda];
    for (j = i + 1; j < N && j < i + K + 1; j++) {
        int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j * incX;
        int jy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j * incY;
        double Aij = A[(j - i) + i * lda];
        Y[jy] += tmp1 * Aij;
        tmp2 += Aij * X[jx];
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
