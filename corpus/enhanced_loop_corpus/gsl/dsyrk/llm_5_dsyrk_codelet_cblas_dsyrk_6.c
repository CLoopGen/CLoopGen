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
        for (k = 0; k < K; k++) {
            if (A[i * lda + k] == 0.0 || A[j * lda + k] == 0.0) continue;
            temp += A[i * lda + k] * A[j * lda + k];
        }
        if (temp != 0.0) {
            C[i * ldc + j] += alpha * temp;
        }
    }
}
}
