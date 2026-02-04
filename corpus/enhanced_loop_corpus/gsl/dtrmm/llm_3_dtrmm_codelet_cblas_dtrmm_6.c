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
    int ajj = j * lda + j;
    int step_j = ldb * i + j;
    for (i = 0; i < n1; i++) {
        double temp = 0.;
        int bij = i * ldb + j;
        if (nonunit) {
            temp = A[ajj] * B[bij];
        } else {
            temp = B[bij];
        }
        for (k = j + 1; k < n2; k++) {
            int a_kj = lda * k + j;
            int bik = i * ldb + k;
            temp += A[a_kj] * B[bik];
        }
        B[bij] = alpha * temp;
    }
}
}
