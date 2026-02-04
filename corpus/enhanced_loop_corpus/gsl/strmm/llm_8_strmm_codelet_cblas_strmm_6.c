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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        if (nonunit) {
            temp = A[j * lda + j] * B[i * ldb + j];
        } else {
            temp = B[i * ldb + j];
        }
        for (k = j + 2; k < n2; k += 2) {
            if (k + 1 < n2) {
                temp += A[lda * k + j] * B[i * ldb + k] +
                        A[lda * (k + 1) + j] * B[i * ldb + (k + 1)];
            } else {
                temp += A[lda * k + j] * B[i * ldb + k];
            }
        }
        // Handle case when loop bound is odd and k == n2-1 was skipped
        if ((n2 - j - 1) % 2 == 1 && j + 1 < n2) {
            temp += A[lda * (j + 1) + j] * B[i * ldb + (j + 1)];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
