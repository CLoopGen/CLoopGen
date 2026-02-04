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
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = j_min * incX;
    int jy = j_min * incY;
    // Force consecutive memory access for A using a local array to accumulate updates
    float temp_Y_updates[K > 0 ? K : 1]; // Small local buffer for delayed write-back
    int update_count = 0;
    Y[iy] += tmp1 * A[i * lda];
    for (j = j_min; j < j_max; j++) {
        float Aij = A[(j - i) + i * lda];
        temp_Y_updates[update_count++] = tmp1 * Aij; // Stash updates
        tmp2 += Aij * X[jx];
        jx += incX;
        jy += incY;
    }
    // Apply stashed writes with consecutive memory access to Y
    jy = j_min * incY;
    for (int k = 0; k < update_count; k++) {
        Y[jy] += temp_Y_updates[k];
        jy += incY;
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
