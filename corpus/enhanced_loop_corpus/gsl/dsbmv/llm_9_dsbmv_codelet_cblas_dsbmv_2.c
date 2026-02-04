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
if (K <= 0) {
    for (i = 0; i < N; i++) {
        Y[iy] += alpha * X[ix] * A[i * lda];
        ix += incX;
        iy += incY;
    }
} else {
    for (i = 0; i < N; i++) {
        double tmp1 = alpha * X[ix];
        double tmp2 = 0.0;
        const int j_min = i + 1;
        const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
        
        Y[iy] += tmp1 * A[i * lda];
        
        for (j = j_min; j < j_max; j++) {
            int offset = (j - i) + i * lda;
            double Aij = A[offset];
            int j_index = ((incY) > 0 ? 0 : (N-1)*(-incY)) + j*incY;
            int x_index = ((incX) > 0 ? 0 : (N-1)*(-incX)) + j*incX;
            
            Y[j_index] += tmp1 * Aij;
            tmp2 += Aij * X[x_index];
        }
        Y[iy] += alpha * tmp2;
        ix += incX;
        iy += incY;
    }
}
}
