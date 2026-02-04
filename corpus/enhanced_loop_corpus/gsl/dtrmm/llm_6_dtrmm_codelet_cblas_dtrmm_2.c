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
for (i = n1; i > 0 && i--;) {
    double temp_vec[64]; // Local accumulation array to modify dependency structure
    for (j = 0; j < n2; j++) {
        temp_vec[j] = 0.;
        for (k = 0; k < i; k++) {
            temp_vec[j] += A[lda * i + k] * B[k * ldb + j];
        }
        if (nonunit) {
            temp_vec[j] += A[i * lda + i] * B[i * ldb + j];
        } else {
            temp_vec[j] += B[i * ldb + j];
        }
        B[ldb * i + j] = alpha * temp_vec[j];
    }
}
}
