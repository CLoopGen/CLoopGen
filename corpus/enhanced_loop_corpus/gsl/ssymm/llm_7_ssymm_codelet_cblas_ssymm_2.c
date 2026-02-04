#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    float temp1_cache[n2]; // Eliminate RAW dependency across k-loop by precomputing temp1 per j
    for (j = 0; j < n2; j++) {
        temp1_cache[j] = alpha * B[ldb * i + j];
    }
    for (j = 0; j < n2; j++) {
        const float temp1 = temp1_cache[j];
        float temp2 = 0.;
        // Move accumulation of C[i*ldc+j] to after inner loop to change dependency order
        for (k = i + 1; k < n1; k++) {
            const float Aik = A[i * lda + k];
            C[k * ldc + j] += Aik * temp1;
            temp2 += Aik * B[ldb * k + j];
        }
        // Delayed write to C[i*ldc+j] to remove early write and modify loop-carried WAW pattern
        C[i * ldc + j] += temp1 * A[i * lda + i] + alpha * temp2;
    }
}
}
