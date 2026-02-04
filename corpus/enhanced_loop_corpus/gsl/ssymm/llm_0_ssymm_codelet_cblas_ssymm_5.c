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
        k = 0;
        for (; k < j; k += 2) {
            const float Ajk0 = A[j * lda + k];
            C[i * ldc + k] += temp1 * Ajk0;
            temp2 += B[ldb * i + k] * Ajk0;
            if (k + 1 < j) {
                const float Ajk1 = A[j * lda + k + 1];
                C[i * ldc + k + 1] += temp1 * Ajk1;
                temp2 += B[ldb * i + k + 1] * Ajk1;
            }
        }
        C[i * ldc + j] += temp1 * A[j * lda + j] + alpha * temp2;
    }
}
}
