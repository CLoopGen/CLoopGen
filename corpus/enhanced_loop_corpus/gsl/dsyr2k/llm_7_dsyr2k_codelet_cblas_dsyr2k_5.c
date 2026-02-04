#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *B;
extern  int ldb;
extern double *C;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_store[K * N]; 
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i++) {
        temp_store[k * N + i] = alpha * A[k * lda + i] + alpha * B[k * ldb + i];
    }
}
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i++) {
        double base_factor = temp_store[k * N + i];
        for (j = i; j < N; j++) {
            C[i * lda + j] += base_factor * (B[k * ldb + j] + A[k * lda + j]);
        }
    }
}
}
