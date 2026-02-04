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
        const float temp1 = alpha * B[i + ldb * j];
        float temp2 = 0.;
        C[i + ldc * j] += temp1 * A[j + lda * j];
        for (k = j + 1; k < n2; k++) {
            const float Ajk = A[j + lda * k];
            C[i + ldc * k] += temp1 * Ajk;
            temp2 += B[i + ldb * k] * Ajk;
        }
        C[i + ldc * j] += alpha * temp2;
    }
}
}
