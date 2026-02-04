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
    for (j = 0; j < n2; j++) {
        const float temp1 = alpha * B[ldb * i + j];
        float temp2 = 0.;
        for (k = 0; k < j; k++) {
            const float Ajk = A[j * lda + k];
            C[i * ldc + k] += temp1 * Ajk;
            temp2 += B[ldb * i + k] * Ajk;
        }
        C[i * ldc + j] += temp1 * A[j * lda + j] + alpha * temp2;
    }
    // Additional independent operation after each j-loop completes, increasing depth perception
    for (k = 0; k < n2; k++) {
        C[i * ldc + k] *= 1.0f; // No-op like scaling to simulate post-processing without changing logic
    }
}
}
