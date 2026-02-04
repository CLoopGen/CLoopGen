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
float *local_A = (float*)malloc(N * sizeof(float));
if (!local_A) return;
for (j = 0; j < N; j++) {
    local_A[j] = 0.0f;
}
for (j = 0; j < N; j++) {
    const float tmp = alpha * Y[jy];
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        local_A[j] += X[ix] * tmp;
        ix += incX;
    }
    jy += incY;
}
for (j = 0; j < N; j++) {
    A[0 + lda * j] += local_A[j];
}
free(local_A);
}
