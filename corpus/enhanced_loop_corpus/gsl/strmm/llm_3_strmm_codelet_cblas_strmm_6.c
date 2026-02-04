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
for (j = 0; j < n2; j++) {
    int ajj = j * lda + j;
    for (i = 0; i < n1; i++) {
        float temp = 0.;
        int bij = i * ldb + j;
        if (nonunit) {
            temp = A[ajj] * B[bij];
        } else {
            temp = B[bij];
        }
        for (k = j + 1; k < n2; k++) {
            int akj = lda * k + j;
            int bik = i * ldb + k;
            temp += A[akj] * B[bik];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
