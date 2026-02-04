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
        const int offset_A = lda * i + j;
        const int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j * incX;
        const int jy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j * incY;
        Y[jy] += temp1 * A[offset_A];
        temp2 += X[jx] * A[offset_A];
    }
    Y[iy] += alpha * temp2;
    ix += incX;
    iy += incY;
}
}
