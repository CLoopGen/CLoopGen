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
        // Introduce artificial dependency on previous j iteration via temp_accum
        double temp_accum = (j > 0) ? B[i * ldb + (j-1)] * alpha : 0.0;
        if (nonunit) {
            temp = A[j * lda + j] * B[i * ldb + j];
        } else {
            temp = B[i * ldb + j];
        }
        for (k = j + 1; k < n2; k++) {
            temp += A[lda * j + k] * B[i * ldb + k];
        }
        temp += temp_accum; // Add dependency on prior result (RAW-like chain across j)
        B[ldb * i + j] = alpha * temp;
    }
}
}
