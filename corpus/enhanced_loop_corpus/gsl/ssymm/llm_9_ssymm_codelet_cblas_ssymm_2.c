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
for (i = 0; i < n1; i += 2) {
    const int bound_i = (i + 1 < n1) ? i + 2 : i + 1;
    for (j = 0; j < n2; j++) {
        for (int ii = i; ii < bound_i; ++ii) {
            const float temp1 = alpha * B[ldb * ii + j];
            float temp2 = 0.;
            C[ii * ldc + j] += temp1 * A[ii * lda + ii];
            for (k = ii + 1; k < n1; k++) {
                const float Aik = A[ii * lda + k];
                C[k * ldc + j] += Aik * temp1;
                temp2 += Aik * B[ldb * k + j];
            }
            C[ii * ldc + j] += alpha * temp2;
        }
    }
}
}
