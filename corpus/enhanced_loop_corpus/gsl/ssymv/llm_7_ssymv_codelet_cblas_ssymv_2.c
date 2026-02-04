#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float temp1 = alpha * X[ix];
    float temp2 = 0.;
    Y[iy] += temp1 * A[lda * i + i];
    for (j = i + 1; j < N; j++) {
        int jx = ix + (j - i) * incX;
        int jy = iy + (j - i) * incY;
        Y[jy] += temp1 * A[lda * i + j];
        temp2 += X[jx] * A[lda * i + j];
    }
    Y[iy] += alpha * temp2;
    ix += incX;
    iy += incY;
}
}
