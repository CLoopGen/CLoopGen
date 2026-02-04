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
if (N <= 0) return;
float *temp_Y = (float*)malloc(N * sizeof(float));
for (int ii = 0; ii < N; ii++) temp_Y[ii] = 0.0f;

for (i = 0; i < N; i++) {
    float tmp1 = alpha * X[ix];
    const int j_min = (i > K) ? i - K : 0;
    for (j = j_min; j < i; j++) {
        float Aij = A[(K - i + j) + i * lda];
        int jy_idx = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j * incY;
        temp_Y[j] += tmp1 * Aij;
    }
    int self_jy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + i * incY;
    temp_Y[i] += tmp1 * A[K + i * lda];
    ix += incX;
    iy += incY;
}

ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
iy = ((incY) > 0 ? 0 : (N - 1) * (-incY));

for (i = 0; i < N; i++) {
    float tmp2 = 0.0f;
    const int j_min = (i > K) ? i - K : 0;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    for (j = j_min; j < i; j++) {
        float Aij = A[(K - i + j) + i * lda];
        tmp2 += Aij * X[jx];
        jx += incX;
    }
    Y[iy] += temp_Y[i] + alpha * tmp2;
    iy += incY;
}

free(temp_Y);
}
