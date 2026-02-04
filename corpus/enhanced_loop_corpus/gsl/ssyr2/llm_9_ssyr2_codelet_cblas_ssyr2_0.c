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
for (i = 0; i < N; i += 2) {
    const float tmp1_i = alpha * X[ix];
    const float tmp2_i = alpha * Y[iy];
    int jx = ix;
    int jy = iy;
    const int bound = (i + 1 < N) ? N : i + 1;
    for (j = i; j < bound; j++) {
        A[lda * i + j] += tmp1_i * Y[jy] + tmp2_i * X[jx];
        jx += incX;
        jy += incY;
    }
    if (i + 1 < N) {
        const float tmp1_i1 = alpha * X[ix + incX];
        const float tmp2_i1 = alpha * Y[iy + incY];
        jx = ix;
        jy = iy;
        for (j = i + 1; j < N; j++) {
            A[lda * (i + 1) + j] += tmp1_i1 * Y[jy] + tmp2_i1 * X[jx];
            jx += incX;
            jy += incY;
        }
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
