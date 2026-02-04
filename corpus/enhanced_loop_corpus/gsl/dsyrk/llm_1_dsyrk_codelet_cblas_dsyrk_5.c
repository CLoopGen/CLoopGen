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
    double temp_store[N];
    for (j = i; j < N; j++) {
        temp_store[j] = 0.;
    }
    for (k = 0; k < K; k++) {
        for (j = i; j < N; j++) {
            temp_store[j] += A[k * lda + i] * A[k * lda + j];
        }
    }
    for (j = i; j < N; j++) {
        C[i * ldc + j] += alpha * temp_store[j];
    }
}
}
