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
for (j = 0; j < N; j++) {
    float temp_sum = 0.0f;
    const float tmp = alpha * Y[jy];
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        temp_sum += X[ix] * tmp;
        ix += incX;
    }
    A[M/2 + lda * j] += temp_sum;
    jy += incY;
}
}
