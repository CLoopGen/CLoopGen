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
        double temp_local;
        for (j = 0; j <= i; j++) {
            temp_local = 0.;
            for (k = 0; k < K; k++) {
                temp_local += A[i * lda + k] * A[j * lda + k];
            }
            C[i * ldc + j] = alpha * temp_local + C[i * ldc + j];
        }
    }
}
