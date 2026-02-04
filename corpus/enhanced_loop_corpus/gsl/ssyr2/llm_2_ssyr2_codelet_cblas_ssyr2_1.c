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
    int jx = 0;
    int jy = 0;
    // Modify memory access to use consecutive indexing with precomputed offsets
    for (j = 0; j <= i; j++) {
        int offset_x = (incX > 0) ? j * incX : (N - 1 - j) * (-incX);
        int offset_y = (incY > 0) ? j * incY : (N - 1 - j) * (-incY);
        A[lda * i + j] += tmp1 * Y[offset_y] + tmp2 * X[offset_x];
    }
    ix += incX;
    iy += incY;
}
}
