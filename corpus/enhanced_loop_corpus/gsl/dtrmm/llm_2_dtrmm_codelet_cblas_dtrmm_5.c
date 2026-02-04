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
        int aj_offset = j * lda;
        int bi_offset = i * ldb;
        if (nonunit) {
            temp = A[aj_offset + j] * B[bi_offset + j];
        } else {
            temp = B[bi_offset + j];
        }
        for (k = j + 1; k < n2; k++) {
            temp += A[aj_offset + k] * B[bi_offset + k];
        }
        B[bi_offset + j] = alpha * temp;
    }
}
}
