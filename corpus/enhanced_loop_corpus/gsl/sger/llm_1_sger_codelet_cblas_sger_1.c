#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int ii, jj;
    for (jj = 0; jj < N; jj++) {
        const float tmp = alpha * Y[jy];
        int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
        for (ii = 0; ii < M; ii++) {
            A[ii + lda * jj] += X[ix] * tmp;
            ix += incX;
        }
        jy += incY;
    }
    for (; j < N; j++) {
        jy += incY;
    }
}
