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
    const int base_ix = ix;
    const int base_iy = iy;
    float temp1 = alpha * X[base_ix];
    float temp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    Y[base_iy] += temp1 * A[lda * i + i];
    for (j = j_min; j < j_max; j++) {
        const int relative_j = j - j_min;
        const int jx = base_ix + relative_j * incX;
        const int jy = base_iy + relative_j * incY;
        const int a_index = lda * i + j;
        Y[jy] += temp1 * A[a_index];
        temp2 += X[jx] * A[a_index];
    }
    Y[base_iy] += alpha * temp2;
    ix += incX;
    iy += incY;
}
}
