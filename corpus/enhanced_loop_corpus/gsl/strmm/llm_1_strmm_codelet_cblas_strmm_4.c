#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *B;
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
    for (j = n2; j > 0; --j) {
        float temp = 0.;
        int index_j = j - 1;
        for (k = 0; k < index_j; k++) {
            temp += A[lda * k + index_j] * B[i * ldb + k];
        }
        if (nonunit) {
            temp += A[index_j * lda + index_j] * B[i * ldb + index_j];
        } else {
            temp += B[i * ldb + index_j];
        }
        B[ldb * i + index_j] = alpha * temp;
    }
}
}
