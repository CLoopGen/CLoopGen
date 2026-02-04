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
    if (i + 1 >= n1) continue;
    for (j = 0; j < n2; j++) {
        double temp_i1 = 0., temp_i2 = 0.;
        // Process two rows simultaneously: i and i+1
        if (nonunit) {
            temp_i1 = A[i * lda + i] * B[i * ldb + j];
            temp_i2 = A[(i+1) * lda + (i+1)] * B[(i+1) * ldb + j];
        } else {
            temp_i1 = B[i * ldb + j];
            temp_i2 = B[(i+1) * ldb + j];
        }
        for (k = i + 1; k < n1; k++) {
            temp_i1 += A[lda * k + i] * B[k * ldb + j];
            temp_i2 += A[lda * k + (i+1)] * B[k * ldb + j];
        }
        B[ldb * i + j] = alpha * temp_i1;
        B[ldb * (i+1) + j] = alpha * temp_i2;
    }
}
}
