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
for (i = 0; i < n1; i += 2) {
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            if (nonunit) {
                double Ajj = A[lda * j + j];
                B[ldb * i + j] /= Ajj;
                B[ldb * (i+1) + j] /= Ajj;
            }
            double Bij1 = B[ldb * i + j];
            double Bij2 = B[ldb * (i+1) + j];
            for (k = j + 1; k < n2; k++) {
                double A_val = A[j * lda + k];
                B[ldb * i + k] -= A_val * Bij1;
                B[ldb * (i+1) + k] -= A_val * Bij2;
            }
        }
    } else {
        for (j = 0; j < n2; j++) {
            if (nonunit) {
                double Ajj = A[lda * j + j];
                B[ldb * i + j] /= Ajj;
            }
            double Bij = B[ldb * i + j];
            for (k = j + 1; k < n2; k++) {
                B[ldb * i + k] -= A[j * lda + k] * Bij;
            }
        }
    }
}
}
