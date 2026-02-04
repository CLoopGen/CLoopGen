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
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        double temp = 0.;
        int B_ptr = i * ldb + j;
        if (nonunit) {
            temp = A[i * lda + i] * B[B_ptr];
        } else {
            temp = B[B_ptr];
        }
        for (k = i + 1; k < n1; k++) {
            temp += A[k * lda + i] * B[k * ldb + j];
        }
        B[B_ptr] = alpha * temp;
    }
}
}
