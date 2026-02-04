#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect indexing through precomputed index arrays to enable irregular access patterns
int *index_map = (int*)alloca(N * sizeof(int));
float *x_cache = (float*)alloca(N * sizeof(float));
// Precompute effective indices in X and cache values
for (int idx = 0; idx < N; idx++) {
    index_map[idx] = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + idx * incX;
    x_cache[idx] = X[index_map[idx]];
}
ix = index_map[0]; // Reset ix to first actual index
for (i = 0; i < N; i++) {
    float tmp = x_cache[i];
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    for (j = j_min; j < j_max; j++) {
        const float Aij = A[lda * i + (K + j - i)]; // Original access pattern for A
        tmp -= Aij * x_cache[j]; // Indirect access via cached x values
    }
    if (nonunit) {
        x_cache[i] = tmp / A[lda * i + K];
    } else {
        x_cache[i] = tmp;
    }
    // Write back updated value if this position is within bounds
    X[index_map[i]] = x_cache[i];
    if (i + 1 < N) ix = index_map[i + 1]; // Update ix for next iteration
}
}
