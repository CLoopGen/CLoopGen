#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern double *B;
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
    for (j = n2 - 1; j >= 0; j--) {
        if (i >= n1) continue;
        double temp = 0.0;
        for (k = 0; k < j; k++) {
            temp += A[lda * k + j] * B[i * ldb + k];
        }
        if (nonunit) {
            temp += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        B[ldb * i + j] = alpha * temp;

        if (i + 1 < n1) {
            double temp2 = 0.0;
            for (k = 0; k < j; k++) {
                temp2 += A[lda * k + j] * B[(i+1) * ldb + k];
            }
            if (nonunit) {
                temp2 += A[j * lda + j] * B[(i+1) * ldb + j];
            } else {
                temp2 += B[(i+1) * ldb + j];
            }
            B[ldb * (i+1) + j] = alpha * temp2;
        }
    }
}
}
