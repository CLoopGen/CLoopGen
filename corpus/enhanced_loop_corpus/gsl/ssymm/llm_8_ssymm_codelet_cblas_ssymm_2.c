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
        C[i * ldc + j] += temp1 * A[i * lda + i];
        for (k = i + 2; k < n1; k += 2) {
            const float Aik0 = A[i * lda + k];
            const float Aik1 = (k + 1 < n1) ? A[i * lda + k + 1] : 0.0f;
            C[k * ldc + j] += Aik0 * temp1;
            if (k + 1 < n1) {
                C[(k + 1) * ldc + j] += Aik1 * temp1;
            }
            temp2 += Aik0 * B[ldb * k + j];
            if (k + 1 < n1) {
                temp2 += Aik1 * B[ldb * (k + 1) + j];
            }
        }
        if ((n1 - i - 1) % 2 == 1 && i + 1 < n1) {
            const int k = n1 - 1;
            const float Aik = A[i * lda + k];
            temp2 += Aik * B[ldb * k + j];
        }
        C[i * ldc + j] += alpha * temp2;
    }
}
}
