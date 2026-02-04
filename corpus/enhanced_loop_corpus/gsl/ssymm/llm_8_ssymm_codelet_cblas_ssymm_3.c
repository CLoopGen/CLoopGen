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
        for (k = 0; k < i; k += 2) {
            const float Aik1 = A[i * lda + k];
            C[k * ldc + j] += Aik1 * temp1;
            temp2 += Aik1 * B[ldb * k + j];
            if (k + 1 < i) {
                const float Aik2 = A[i * lda + k + 1];
                C[(k + 1) * ldc + j] += Aik2 * temp1;
                temp2 += Aik2 * B[ldb * k + 1 + j];
            }
        }
        C[i * ldc + j] += temp1 * A[i * lda + i] + alpha * temp2;
    }
}
}
