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
    if (N <= 0 || M <= 0) return;
    for (j = 0; j < N; j++) {
        const float tmp = alpha * Y[jy];
        int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
        i = 0;
        if (incX == 1) {
            for (; i < M; i++) {
                A[i + lda * j] += X[ix] * tmp;
                ix++;
            }
        } else {
            for (; i < M; i++) {
                A[i + lda * j] += X[ix] * tmp;
                ix += incX;
            }
        }
        jy += incY;
    }
}
