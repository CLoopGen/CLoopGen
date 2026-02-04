#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
    for (j = 0; j < n2; j += 2) {
        if (nonunit && j + 1 < n2) {
            double Ajj1 = A[lda * j + j];
            double Ajj2 = A[lda * (j+1) + (j+1)];
            B[ldb * i + j] /= Ajj1;
            B[ldb * i + j + 1] /= Ajj2;
        } else if (nonunit) {
            double Ajj = A[lda * j + j];
            B[ldb * i + j] /= Ajj;
        }
        {
            double Bij = B[ldb * i + j];
            for (k = j + 1; k < n2; k++) {
                B[ldb * i + k] -= A[j * lda + k] * Bij;
            }
        }
        if (j + 1 < n2) {
            double Bij2 = B[ldb * i + j + 1];
            for (k = j + 2; k < n2; k++) {
                B[ldb * i + k] -= A[(j+1) * lda + k] * Bij2;
            }
        }
    }
}
}
