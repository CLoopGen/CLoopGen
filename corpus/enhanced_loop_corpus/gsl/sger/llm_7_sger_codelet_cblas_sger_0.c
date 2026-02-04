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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_A = (float*)alloca(M * N * sizeof(float));
// Eliminate RAW/WAR dependencies by using local accumulation buffer
for (i = 0; i < M; i++) {
    const float tmp = alpha * X[ix];
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        local_A[i * N + j] = Y[jy] * tmp;
        jy += incY;
    }
    ix += incX;
}
// Decouple computation from update: no loop-carried dependency in first loop
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        A[lda * i + j] += local_A[i * N + j];
    }
}
}
