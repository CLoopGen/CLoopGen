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
        for (k = j; k < n2; k++) {
            if (k == j && nonunit) {
                temp += A[j * lda + j] * B[i * ldb + j];
            } else if (k > j) {
                temp += A[lda * k + j] * B[i * ldb + k];
            }
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
