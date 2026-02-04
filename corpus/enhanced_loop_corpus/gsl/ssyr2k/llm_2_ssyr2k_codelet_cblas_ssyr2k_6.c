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
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        float temp = 0.;
        const float *a_ptr = &A[i * lda];
        const float *b_ptr = &B[j * ldb];
        const float *b_iptr = &B[i * ldb];
        const float *a_jptr = &A[j * lda];
        for (k = 0; k < K; k++) {
            temp += (a_ptr[k] * b_ptr[k] + b_iptr[k] * a_jptr[k]);
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
