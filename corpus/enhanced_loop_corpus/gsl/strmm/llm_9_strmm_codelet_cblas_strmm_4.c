#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i += 2) {
    if (i >= n1) break;
    for (j = n2; j > 0 && j--;) {
        float temp_i0 = 0.0;
        float temp_i1 = 0.0;
        for (k = 0; k < j; k++) {
            temp_i0 += A[lda * k + j] * B[i * ldb + k];
            if (i + 1 < n1) {
                temp_i1 += A[lda * k + j] * B[(i+1) * ldb + k];
            }
        }
        if (nonunit) {
            temp_i0 += A[j * lda + j] * B[i * ldb + j];
            if (i + 1 < n1) {
                temp_i1 += A[j * lda + j] * B[(i+1) * ldb + j];
            }
        } else {
            temp_i0 += B[i * ldb + j];
            if (i + 1 < n1) {
                temp_i1 += B[(i+1) * ldb + j];
            }
        }
        B[ldb * i + j] = alpha * temp_i0;
        if (i + 1 < n1) {
            B[ldb * (i+1) + j] = alpha * temp_i1;
        }
    }
}
}
