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
double *temp_Y = (double*)alloca(N * sizeof(double));
for (int k = 0; k < N; k++) temp_Y[k] = 0.0;

for (i = 0; i < N; i++) {
    double tmp1 = alpha * X[ix];
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    Y[iy] += tmp1 * A[i * lda]; 
    for (j = j_min; j < j_max; j++) {
        double Aij = A[(j - i) + i * lda];
        temp_Y[j] += tmp1 * Aij;
        jx += incX;
    }
    temp_Y[i] += alpha * tmp1 * A[i * lda];
    ix += incX;
    iy += incY;
}

iy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
for (i = 0; i < N; i++) {
    Y[iy] += temp_Y[i];
    iy += incY;
}
}
