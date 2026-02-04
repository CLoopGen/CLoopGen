#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    double local_scale = alpha * alpha; // Remove redundant recomputation across j
    for (k = 0; k < n2; k++) {
        // Precompute a temporary vector to eliminate loop-carried dependencies
        double scratch = (nonunit) ? A[k * lda + k] : 1.0;
        for (j = 0; j <= k; j++) {
            int idx_b = i * ldb + j;
            int idx_a = lda * j + k;
            if (k == j) {
                if (nonunit) {
                    B[idx_b] = local_scale * (scratch * B[idx_b]);
                } else {
                    B[idx_b] = local_scale * B[idx_b];
                }
            } else if (k > j) {
                // Accumulate contribution of A[j][k] * B[i][k] into B[i][j]
                // Reverse access pattern: use future k values early
                double temp = A[idx_a] * B[i * ldb + k];
                B[i * ldb + j] += local_scale * temp;
            }
        }
    }
}
}
