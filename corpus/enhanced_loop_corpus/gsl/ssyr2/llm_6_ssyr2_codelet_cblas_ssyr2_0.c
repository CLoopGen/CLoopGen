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
for (i = 0; i < N; i++) {
    const float tmp1 = alpha * X[ix];
    const float tmp2 = alpha * Y[iy];
    int jx = ix;
    int jy = iy;
    float temp_accum = 0.0f;
    for (j = i; j < N; j++) {
        temp_accum += tmp1 * Y[jy] + tmp2 * X[jx];
        A[lda * i + j] += temp_accum;
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}
}
