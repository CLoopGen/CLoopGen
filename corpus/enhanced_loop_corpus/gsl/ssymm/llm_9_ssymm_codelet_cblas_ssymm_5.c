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
for (i = 0; i < n1; i += 2) { // Block outer loop by 2 to increase data reuse and computational intensity
    for (j = 0; j < n2; j++) {
        float temp1_0 = 0.0f, temp1_1 = 0.0f;
        float temp2_0 = 0.0f, temp2_1 = 0.0f;
        if (i < n1) temp1_0 = alpha * B[ldb * i + j];
        if (i + 1 < n1) temp1_1 = alpha * B[ldb * (i+1) + j];
        for (k = 0; k < j; k++) {
            const float Ajk = A[j * lda + k];
            if (i < n1) {
                C[i * ldc + k] += temp1_0 * Ajk;
                temp2_0 += B[ldb * i + k] * Ajk;
            }
            if (i + 1 < n1) {
                C[(i+1) * ldc + k] += temp1_1 * Ajk;
                temp2_1 += B[ldb * (i+1) + k] * Ajk;
            }
        }
        if (i < n1) {
            C[i * ldc + j] += temp1_0 * A[j * lda + j] + alpha * temp2_0;
        }
        if (i + 1 < n1) {
            C[(i+1) * ldc + j] += temp1_1 * A[j * lda + j] + alpha * temp2_1;
        }
    }
}
}
