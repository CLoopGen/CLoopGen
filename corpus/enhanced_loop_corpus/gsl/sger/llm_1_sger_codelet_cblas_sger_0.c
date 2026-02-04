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
int jy_base = (incY > 0 ? 0 : (N - 1) * (-incY));
for (i = 0; i < M; i++) {
    const float tmp = alpha * X[ix];
    for (j = 0; j < N; j++) {
        int jy = jy_base + j * incY;
        A[lda * i + j] += Y[jy] * tmp;
    }
    ix += incX;
}
}
