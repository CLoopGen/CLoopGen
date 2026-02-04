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
        for (k = 0; k < j; k++) {
            temp += A[k * lda + j] * B[k * ldb + i];
        }
        if (nonunit) {
            temp += A[j * lda + j] * B[j * ldb + i];
        } else {
            temp += B[j * ldb + i];
        }
        B[j * ldb + i] = alpha * temp;
    }
}
}
