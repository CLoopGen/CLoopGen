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
double *temp_arr = (double*)alloca(n1 * sizeof(double));
for (j = n2 - 1; j >= 0; j--) {
    for (i = 0; i < n1; i++) {
        double temp = 0.;
        for (k = 0; k < j; k++) {
            temp += A[lda * j + k] * B[i * ldb + k];
        }
        if (nonunit) {
            temp += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        temp_arr[i] = alpha * temp;
    }
    for (i = 0; i < n1; i++) {
        B[ldb * i + j] = temp_arr[i];
    }
}
}
