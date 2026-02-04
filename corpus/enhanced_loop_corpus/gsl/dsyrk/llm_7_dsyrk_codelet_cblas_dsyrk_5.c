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
        for (j = i; j < N; j++) {
            double temp = 0.0;
            int kk;
            // Split the k-loop into two halves to introduce loop-carried dependencies artificially
            for (kk = 0; kk < K; kk += 2) {
                if (kk + 1 < K) {
                    // Process two iterations at once — creates intra-iteration dependency via combined access
                    temp += A[kk * lda + i] * A[kk * lda + j] +
                            A[(kk + 1) * lda + i] * A[(kk + 1) * lda + j];
                } else {
                    temp += A[kk * lda + i] * A[kk * lda + j];
                }
            }
            // Add artificial dependency on previous j iteration (introduces loop-carried RAW)
            if (j > i) {
                double prev_val = C[i * ldc + j - 1];
                temp += (prev_val * alpha) * 1e-10; // Weak dependence, preserves semantics approximately
            }
            C[i * ldc + j] += alpha * temp;
        }
    }
}
