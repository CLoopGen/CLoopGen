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
    float temp2 = 0.0f;
    Y[iy] += temp1 * A[lda * i + i];
    for (j = i + 1; j < N; j += 2) {
        const int j_next = j + 1;
        Y[iy + (j - i) * incY] += temp1 * A[lda * i + j];
        temp2 += X[ix + (j - i) * incX] * A[lda * i + j];
        if (j_next < N) {
            Y[iy + (j_next - i) * incY] += temp1 * A[lda * i + j_next];
            temp2 += X[ix + (j_next - i) * incX] * A[lda * i + j_next];
        }
    }
    Y[iy] += alpha * temp2;
    ix += incX;
    iy += incY;
}
}
