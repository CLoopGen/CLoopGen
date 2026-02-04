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
if (N <= 0) return;
float temp1, temp2;
int base_iy;

for (i = 0; i < N; i++) {
    temp1 = alpha * X[ix];
    temp2 = 0.0f;
    base_iy = iy;
    Y[base_iy] += temp1 * A[lda * i + i];

    for (int k = 0; k < N - i - 1; k++) {
        int j = i + 1 + k;
        int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j * incX;
        int jy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j * incY;
        int idx_A = lda * i + j;
        Y[jy] += temp1 * A[idx_A];
        temp2 += X[jx] * A[idx_A];
    }

    Y[base_iy] += alpha * temp2;
    ix += incX;
    iy += incY;
}
}
