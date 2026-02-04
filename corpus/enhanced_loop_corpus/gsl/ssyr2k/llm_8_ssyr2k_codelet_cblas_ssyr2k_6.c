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
    for (j = 0; j <= i; j += 2) {  // Increased stride to reduce trip count
        float temp1 = 0., temp2 = 0.;
        for (k = 0; k < K - 1; k += 2) {  // Unrolled inner loop with step 2 to increase arithmetic per iteration
            temp1 += A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k];
            temp2 += A[i * lda + k + 1] * B[j * ldb + k + 1] + B[i * ldb + k + 1] * A[j * lda + k + 1];
        }
        if (k < K) {  // Handle odd K
            temp1 += A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k];
        }
        C[i * ldc + j] += alpha * (temp1 + temp2);
        if (j + 1 <= i) {
            C[i * ldc + j + 1] += alpha * temp1;  // Additional write to increase memory traffic
        }
    }
}
}
