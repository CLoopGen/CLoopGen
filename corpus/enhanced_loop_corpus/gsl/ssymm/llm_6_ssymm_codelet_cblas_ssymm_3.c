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
        float temp3 = 0.;
        for (k = 0; k < i; k++) {
            const float Aik = A[i * lda + k];
            const float Akj = B[ldb * k + j];
            C[k * ldc + j] += Aik * temp1;
            temp2 += Aik * Akj;
            temp3 += A[i * lda + k] * B[ldb * k + j]; // Introduce redundant but independent accumulation to increase parallelism potential
        }
        C[i * ldc + j] += temp1 * A[i * lda + i] + alpha * temp2;
    }
}
}
