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
    // Variant 2: Strided Indirect Access via Index Arrays (Simulating Irregular Access Patterns)
    // Precompute indirect access indices for A, X, and Y to simulate strided/indirect pattern

    int *index_i = (int*)alloca(N * sizeof(int));
    int *index_jx = (int*)alloca(N * sizeof(int));
    int *index_jy = (int*)alloca(N * sizeof(int));
    int *index_A_diag = (int*)alloca(N * sizeof(int));
    int *index_A_off = (int*)alloca(N * sizeof(int));

    // Precompute base indices for indirect addressing
    int base_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
    int base_iy = ((incY) > 0 ? 0 : (N - 1) * (-incY));

    for (int idx = 0; idx < N; idx++) {
        index_i[idx] = base_iy + idx * incY;
        index_jx[idx] = base_ix + idx * incX;
        index_jy[idx] = base_iy + idx * incY;
        index_A_diag[idx] = idx * lda;           // For A[0 + i*lda]
        index_A_off[idx] = idx * lda;            // Base offset for A[(j-i)+i*lda]
    }

    // Use precomputed indices to enforce strided/indirect memory access
    for (i = 0; i < N; i++) {
        double tmp1 = alpha * X[index_jx[i]];
        double tmp2 = 0.0;
        const int j_min = i + 1;
        const int j_max = (N < i + K + 1) ? N : (i + K + 1);

        Y[index_i[i]] += tmp1 * A[i + index_A_diag[i]];  // A[0 + i*lda] -> A[i + i*lda]

        for (j = j_min; j < j_max; j++) {
            int A_offset = (j - i) + index_A_off[i];
            double Aij = A[A_offset];
            Y[index_jy[j]] += tmp1 * Aij;
            tmp2 += Aij * X[index_jx[j]];
        }
        Y[index_i[i]] += alpha * tmp2;
    }

    // Finalize pointer updates (simulated, as ix/iy are extern and used outside)
    // In practice, caller manages ix/iy; we assume full traversal
    ix += N * incX;
    iy += N * incY;
}
