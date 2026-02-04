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
// Use indirect addressing via precomputed index arrays to decouple memory access from loop logic
// Assume auxiliary index arrays are available: precomputed_jx[N], precomputed_jy[N], and col_offsets[K+1]
// Here we simulate their use without external declarations, computing them on-stack for self-containment
int *precomputed_jx = (int*)alloca(N * sizeof(int));
int *precomputed_jy = (int*)alloca(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    precomputed_jx[idx] = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + idx * incX;
    precomputed_jy[idx] = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + idx * incY;
}
for (i = 0; i < N; i++) {
    float tmp1 = alpha * X[ix];
    float tmp2 = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    Y[iy] += tmp1 * A[i * lda];
    for (j = j_min; j < j_max; j++) {
        float Aij = A[(j - i) + i * lda];
        int jx_idx = precomputed_jx[j];
        int jy_idx = precomputed_jy[j];
        Y[jy_idx] += tmp1 * Aij;
        tmp2 += Aij * X[jx_idx];
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
