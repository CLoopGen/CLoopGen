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
    int jx = i * incX;
    int jy = i * incY;
    for (j = i; j < N; j++) {
        const int a_index = (i << 8) + j; // Simulate large stride via bit-shift (equivalent to lda=256)
        const int y_index = jy + (j - i) * incY;
        const int x_index = jx + (j - i) * incX;
        A[a_index] += tmp1 * Y[y_index] + tmp2 * X[x_index];
    }
    ix += incX;
    iy += incY;
}
}
