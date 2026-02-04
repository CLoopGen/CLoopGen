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
// Change to fully strided memory access pattern with precomputed indices
int *index_X = (int*)alloca(N * sizeof(int));
double *val_X = (double*)alloca(N * sizeof(double));
const int base_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));

// Precompute all X indices and cache values for consecutive access later
for (int n = 0; n < N; n++) {
    index_X[n] = base_ix + n * incX;
    val_X[n] = X[index_X[n]];
}

for (i = 0; i < N; i++) {
    double tmp = val_X[i];
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    for (j = j_min; j < j_max; j++) {
        const ptrdiff_t A_index = (i - j) + lda * j;
        tmp -= A[A_index] * val_X[j];
    }
    if (nonunit) {
        tmp /= A[lda * i];
    }
    X[index_X[i]] = tmp; // Write back through precomputed index
}
}
