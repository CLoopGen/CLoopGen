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
    for (j = i; j < N; j += 2) {
        double temp1 = 0.;
        double temp2 = 0.;
        int j2 = j + 1;
        for (k = 0; k < K; k++) {
            temp1 += A[i * lda + k] * A[j * lda + k];
            if (j2 < N) {
                temp2 += A[i * lda + k] * A[j2 * lda + k];
            }
        }
        C[i * ldc + j] += alpha * temp1;
        if (j2 < N) {
            C[i * ldc + j2] += alpha * temp2;
        }
    }
}
}
