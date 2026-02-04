#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
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
    float tmp1 = alpha * X[ix];
    float tmp2 = 0.;
    const int j_min = (i > K) ? i - K : 0;
    const int j_max = i;
    int j_offset = j_min;
    for (j = j_min; j < j_max; j++) {
        int a_index = (K - i + j) + i * lda;
        int x_index = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_offset * incX;
        int y_index = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_offset * incY;
        float Aij = A[a_index];
        Y[y_index] += tmp1 * Aij;
        tmp2 += Aij * X[x_index];
        j_offset++;
    }
    int final_y_index = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + i * incY;
    Y[final_y_index] += tmp1 * A[K + i * lda] + alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
