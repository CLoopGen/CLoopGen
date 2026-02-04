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
    double temp_local[N]; // Local accumulation array to remove immediate write-back
    for (j = i; j < N; j++) {
        temp_local[j] = 0.0;
        for (k = 0; k < K; k++) {
            temp_local[j] += A[i * lda + k] * A[j * lda + k];
        }
    }
    // Delayed update: eliminate loop-carried dependence on C during computation
    for (j = i; j < N; j++) {
        C[i * ldc + j] += alpha * temp_local[j]; // Final write with no intra-loop C dependence
    }
}
}
