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
    for (j = n2 - 1; j >= 0; j--) {
        double temp = 0.;
        for (k = 0; k <= j; k++) {
            if (k < j) {
                temp += A[lda * k + j] * B[i * ldb + k];
            } else {
                if (nonunit) {
                    temp += A[j * lda + j] * B[i * ldb + j];
                } else {
                    temp += B[i * ldb + j];
                }
            }
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
