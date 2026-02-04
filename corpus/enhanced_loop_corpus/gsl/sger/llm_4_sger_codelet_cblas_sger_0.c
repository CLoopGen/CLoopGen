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
for (i = 0; i < M; i++) {
    const float tmp = alpha * X[ix];
    int jy = 0;
    if (incY < 0) {
        jy = (N - 1) * (-incY);
    }
    for (j = 0; j < N; j++) {
        A[lda * i + j] += Y[jy] * tmp;
        jy += incY;
    }
    ix += incX;
}
}
