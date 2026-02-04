#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
for (i = n1; i > 0; i -= 2) {
    int i1 = i - 1;
    int i2 = i - 2;
    if (i2 < 0) i2 = i1;

    if (nonunit) {
        if (i1 >= 0) {
            float Aii1 = A[lda * i1 + i1];
            for (j = 0; j < n2; j++) {
                B[ldb * i1 + j] /= Aii1;
            }
        }
        if (i2 >= 0 && i2 != i1) {
            float Aii2 = A[lda * i2 + i2];
            for (j = 0; j < n2; j++) {
                B[ldb * i2 + j] /= Aii2;
            }
        }
    }

    for (k = 0; k < i1; k++) {
        if (i1 >= 0) {
            const float Aik1 = A[i1 * lda + k];
            for (j = 0; j < n2; j++) {
                B[ldb * k + j] -= Aik1 * B[ldb * i1 + j];
            }
        }
        if (i2 >= 0 && i2 != i1 && k < i2) {
            const float Aik2 = A[i2 * lda + k];
            for (j = 0; j < n2; j++) {
                B[ldb * k + j] -= Aik2 * B[ldb * i2 + j];
            }
        }
    }
}
}
