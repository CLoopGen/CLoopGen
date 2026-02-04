#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_A = (float*)malloc(lda * N * sizeof(float));
if (!local_A) return;
for (int k = 0; k < lda * N; k++) local_A[k] = A[k];

for (i = 0; i < N; i++) {
    const float tmp1 = alpha * X[ix];
    const float tmp2 = alpha * Y[iy];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j <= i; j++) {
        local_A[lda * j + i] += tmp1 * Y[jy];  
        local_A[lda * i + j] += tmp2 * X[jx];  
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}

for (int k = 0; k < lda * N; k++) {
    A[k] = local_A[k];
}
free(local_A);
}
