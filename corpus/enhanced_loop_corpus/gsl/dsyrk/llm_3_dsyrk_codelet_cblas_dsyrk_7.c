#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        double temp = 0.;
        // Use strided access with precomputed starting indices
        int idx_i = i;
        int idx_j = j;
        for (k = 0; k < K; k++) {
            temp += A[idx_i] * A[idx_j];
            idx_i += lda; // Stride through rows for column i
            idx_j += lda; // Stride through rows for column j
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
