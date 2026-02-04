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
for (i = n1; i > 0 && i--; ) {
    int limit = (i > 8) ? i - 8 : 0;
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        k = 0;
        for (; k < limit; k += 8) {
            temp += A[lda * (k+0) + i] * B[(k+0) * ldb + j];
            temp += A[lda * (k+1) + i] * B[(k+1) * ldb + j];
            temp += A[lda * (k+2) + i] * B[(k+2) * ldb + j];
            temp += A[lda * (k+3) + i] * B[(k+3) * ldb + j];
            temp += A[lda * (k+4) + i] * B[(k+4) * ldb + j];
            temp += A[lda * (k+5) + i] * B[(k+5) * ldb + j];
            temp += A[lda * (k+6) + i] * B[(k+6) * ldb + j];
            temp += A[lda * (k+7) + i] * B[(k+7) * ldb + j];
        }
        for (; k < i; k++) {
            temp += A[lda * k + i] * B[k * ldb + j];
        }
        if (nonunit) {
            temp += A[i * lda + i] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
