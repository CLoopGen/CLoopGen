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
    const float tmp = alpha * Y[jy];
    int* restrict index_array = (int*)alloca(M * sizeof(int));
    for (i = 0; i < M; i++) {
        index_array[i] = i * incX;
    }
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        A[i + lda * j] += X[ix + index_array[i]] * tmp;
        ix += incX;
    }
    jy += incY;
}
}
