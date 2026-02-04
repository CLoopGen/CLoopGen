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
for (i = 0; i < n1; i++) {
    for (k = 0; k < n2; k++) {
        float Bik_prev;
        for (j = 0; j < n2; j++) {
            if (j == 0 && nonunit) {
                float A00 = A[0];
                B[ldb * i + 0] /= A00;
            }
            if (k > j) {
                float Bij = B[ldb * i + j];
                B[ldb * i + k] -= A[k * lda + j] * Bij;
            }
        }
    }
}
}
