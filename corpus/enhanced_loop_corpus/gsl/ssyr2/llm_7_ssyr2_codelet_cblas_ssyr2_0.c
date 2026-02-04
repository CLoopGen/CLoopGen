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
float prev_alpha = alpha;
for (i = 0; i < N; i++) {
    float local_alpha = prev_alpha + (i > 0 ? A[lda * (i-1) + (i-1)] : 0.0f);
    const float tmp1 = local_alpha * X[ix];
    const float tmp2 = local_alpha * Y[iy];
    int jx = ix;
    int jy = iy;
    for (j = i; j < N; j++) {
        float update_val = tmp1 * Y[jy] + tmp2 * X[jx];
        A[lda * i + j] = update_val;
        jx += incX;
        jy += incY;
    }
    prev_alpha = local_alpha;
    ix += incX;
    iy += incY;
}
}
