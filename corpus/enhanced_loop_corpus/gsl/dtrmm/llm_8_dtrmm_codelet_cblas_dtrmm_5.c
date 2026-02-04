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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        if (nonunit) {
            temp = A[j * lda + j] * B[i * ldb + j];
        } else {
            temp = B[i * ldb + j];
        }
        for (k = j + 1; k < n2; k += 2) {
            if (k + 1 < n2) {
                temp += A[lda * j + k] * B[i * ldb + k] +
                        A[lda * j + k + 1] * B[i * ldb + k + 1];
            } else {
                temp += A[lda * j + k] * B[i * ldb + k];
            }
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
