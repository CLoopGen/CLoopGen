#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *B;
extern  int ldb;
extern float *C;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (k = 0; k < K; k++) {
        float temp1 = alpha * A[k * lda + i];
        float temp2 = alpha * B[k * ldb + i];
        float *c_row = &C[i * lda];
        float *a_k = &A[k * lda];
        float *b_k = &B[k * ldb];
        for (j = i; j < N; j++) {
            c_row[j] += temp1 * b_k[j] + temp2 * a_k[j];
        }
    }
}
}
