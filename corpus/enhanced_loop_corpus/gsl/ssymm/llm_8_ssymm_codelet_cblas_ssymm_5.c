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
    for (j = 0; j < n2; j += 2) { // Increased trip count granularity to reduce loop overhead (unrolling by 2)
        const float temp1_0 = alpha * B[ldb * i + j];
        float temp2_0 = 0.;
        float temp2_1 = 0.;
        const float temp1_1 = (j + 1 < n2) ? alpha * B[ldb * i + j + 1] : 0.0f;
        for (k = 0; k < j; k++) {
            const float Ajk0 = A[j * lda + k];
            C[i * ldc + k] += temp1_0 * Ajk0;
            temp2_0 += B[ldb * i + k] * Ajk0;
            if (j + 1 < n2) {
                const float Ajk1 = A[(j+1) * lda + k];
                C[i * ldc + k] += temp1_1 * Ajk1;
                temp2_1 += B[ldb * i + k] * Ajk1;
            }
        }
        C[i * ldc + j] += temp1_0 * A[j * lda + j] + alpha * temp2_0;
        if (j + 1 < n2) {
            C[i * ldc + j + 1] += temp1_1 * A[(j+1)*lda + (j+1)] + alpha * temp2_1;
        }
    }
}
}
