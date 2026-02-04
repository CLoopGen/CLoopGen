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
for (i = 0; i < N; i += 2) {
    double tmp1_0 = alpha * X[ix];
    double tmp1_1 = (i+1 < N) ? alpha * X[ix + incX] : 0.0;
    double tmp2_0 = 0.0;
    double tmp2_1 = 0.0;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    
    Y[iy] += tmp1_0 * A[0 + i * lda];
    if (i+1 < N) {
        Y[iy + incY] += tmp1_1 * A[0 + (i+1)*lda];
    }
    
    for (j = j_min; j < j_max; j++) {
        double Aij_0 = A[(j - i) + i * lda];
        double Aij_1 = (i+1 < N && j < i+K+2 && j < N) ? A[(j - (i+1)) + (i+1)*lda] : 0.0;
        
        Y[jy] += tmp1_0 * Aij_0;
        if (i+1 < N && j >= i+2) {
            int offset = jy - iy + (j >= i+2 ? 0 : 0);
            Y[offset + (i+1)*incY] += tmp1_1 * Aij_1;
        }
        
        tmp2_0 += Aij_0 * X[jx];
        if (i+1 < N && j < N && j >= i+2) {
            tmp2_1 += Aij_1 * X[jx];
        }
        
        jx += incX;
        jy += incY;
    }
    Y[iy] += alpha * tmp2_0;
    if (i+1 < N) {
        Y[iy + incY] += alpha * tmp2_1;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
