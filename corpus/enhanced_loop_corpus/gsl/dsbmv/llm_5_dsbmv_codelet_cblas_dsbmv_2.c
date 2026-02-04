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
    if (i >= K) break;
    double tmp1 = alpha * X[ix];
    double tmp2 = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    Y[iy] += tmp1 * A[0 + i * lda];
    for (j = j_min; j < j_max; j++) {
        double Aij = A[(j - i) + i * lda];
        if (Aij != 0.0) {
            Y[jy] += tmp1 * Aij;
            tmp2 += Aij * X[jx];
        }
        jx += incX;
        jy += incY;
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
