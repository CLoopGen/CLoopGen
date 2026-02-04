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
        // Introduce WAW dependency by splitting the update to C[i*ldc+j] into two distinct steps with intermediate use
        float local_accum = temp1 * A[i * lda + i];
        for (k = i + 1; k < n1; k++) {
            const float Aik = A[i * lda + k];
            C[k * ldc + j] += Aik * temp1;
            temp2 += Aik * B[ldb * k + j];
        }
        C[i * ldc + j] += local_accum + alpha * temp2;
    }
}
}
