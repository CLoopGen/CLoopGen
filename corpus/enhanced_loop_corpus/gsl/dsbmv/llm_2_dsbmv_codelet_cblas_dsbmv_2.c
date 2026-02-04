#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Local Blocking (Unrolled and Reordered for Sequential A Access)
    double *local_X = (double*)alloca(N * sizeof(double));
    double *local_Y = (double*)alloca(N * sizeof(double));
    
    // Pre-load X and Y into contiguous buffers to enable sequential access
    int ix_temp = ((incX) > 0 ? 0 : (N - 1) * (-incX));
    int iy_temp = ((incY) > 0 ? 0 : (N - 1) * (-incY));
    for (int idx = 0; idx < N; idx++) {
        local_X[idx] = X[ix_temp];
        local_Y[idx] = Y[iy_temp];
        ix_temp += incX;
        iy_temp += incY;
    }

    // Reset index pointers for write-back
    ix_temp = ((incX) > 0 ? 0 : (N - 1) * (-incX));
    iy_temp = ((incY) > 0 ? 0 : (N - 1) * (-incY));

    for (i = 0; i < N; i++) {
        double tmp1 = alpha * local_X[i];
        double tmp2 = 0.0;
        const int j_min = i + 1;
        const int j_max = (N < i + K + 1) ? N : (i + K + 1);

        // Now access A in a more predictable, row-wise consecutive manner
        for (j = j_min; j < j_max; j++) {
            double Aij = A[(j - i) + i * lda];
            local_Y[j] += tmp1 * Aij;
            tmp2 += Aij * local_X[j];
        }
        local_Y[i] += tmp1 * A[i * lda] + alpha * tmp2;

        // Update original arrays at the end (or could be done post-loop)
        if (i == N - 1) {
            // Write back all updated values in one pass
            int iy_write = ((incY) > 0 ? 0 : (N - 1) * (-incY));
            for (int idx = 0; idx < N; idx++) {
                Y[iy_write] = local_Y[idx];
                iy_write += incY;
            }
        }
    }

    // Final write-back of X is not needed since it's read-only
}
