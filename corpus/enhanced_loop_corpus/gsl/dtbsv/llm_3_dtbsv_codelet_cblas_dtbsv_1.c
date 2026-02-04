#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Modify memory access pattern to promote consecutive accesses by reordering computations
// Simulate transposed or packed access by precomputing base indices and using local accumulation
int base_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
for (i = 0; i < N; i++) {
    double tmp = X[base_ix + i * incX]; // Make access more predictable
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    // Precompute starting offset in X for inner loop to encourage linear indexing
    int start_jx = base_ix + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        // Force consecutive-like access in A by computing index directly
        const double Aij = A[lda * i + K - (i - j)]; // Maintain banded structure
        tmp -= Aij * X[start_jx + (j - j_min) * incX];
    }
    if (nonunit) {
        X[base_ix + i * incX] = tmp / A[lda * i + K];
    } else {
        X[base_ix + i * incX] = tmp;
    }
}
ix = base_ix + N * incX; // Update global ix as in original
}
