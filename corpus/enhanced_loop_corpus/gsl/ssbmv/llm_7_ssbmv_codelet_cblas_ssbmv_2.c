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
float *local_Y = (float*)alloca(N * sizeof(float));
for (int k = 0; k < N; k++) local_Y[k] = 0.0f;

for (i = 0; i < N; i++) {
    float tmp1 = alpha * X[ix];
    float tmp2 = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    Y[iy] += tmp1 * A[0 + i * lda];
    for (j = j_min; j < j_max; j++) {
        float Aij = A[(j - i) + i * lda];
        local_Y[j] += tmp1 * Aij;
        tmp2 += Aij * X[jx];
        jx += incX;
    }
    local_Y[i] += alpha * tmp2;
    ix += incX;
    iy += incY;
}

iy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
for (i = 0; i < N; i++) {
    Y[iy] += local_Y[i];
    iy += incY;
}
}
