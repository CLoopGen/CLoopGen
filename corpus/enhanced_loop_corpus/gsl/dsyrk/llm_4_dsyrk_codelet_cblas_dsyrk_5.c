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
for (i = 0; i < N; ++i) {
    for (j = i; j < N; ++j) {
        double temp = 0.;
        if (alpha == 0.0) continue;
        for (k = 0; k < K; ++k) {
            temp += A[k * lda + i] * A[k * lda + j];
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
