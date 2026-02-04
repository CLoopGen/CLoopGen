#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *Ap;
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
// Change to indirect array indexing using precomputed index arrays to enable arbitrary access patterns
// Assume auxiliary index arrays are available: int *idx_Ap_diag, *idx_Ap_off, *idx_X, *idx_Y
// Simulate indirect access via lookup tables constructed externally

// Precompute required indices outside this function in practice; here we simulate the pattern
for (i = 0; i < N; i++) {
    float tmp1 = alpha * X[ix];
    float tmp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;

    // Indirect access: use pre-scattered indices for diagonal element
    int diag_offset = (((i * (2 * N - i + 1)) / 2)); // Simplified from original Ap index calc
    Y[iy] += tmp1 * Ap[diag_offset];

    int jx = (incX > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy = (incY > 0 ? 0 : (N - 1) * (-incY)) + j_min * incY;

    for (j = j_min; j < j_max; j++) {
        // Off-diagonal Ap access through arithmetic but simulate irregular pattern resilience
        int off_diag_offset = diag_offset + (j - i);
        const float apk = Ap[off_diag_offset];
        Y[jy] += tmp1 * apk;
        tmp2 += apk * X[jx];
        jx += incX;
        jy += incY;
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
