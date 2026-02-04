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
    for (j = 0; j < n2; j += 2) { // Increase loop stride to reduce trip count and increase computational intensity per iteration
        if (nonunit && j + 1 < n2) {
            double Ajj0 = A[lda * j + j];
            double Ajj1 = A[lda * (j+1) + (j+1)];
            B[ldb * i + j] /= Ajj0;
            B[ldb * i + j + 1] /= Ajj1;
        }
        {
            double Bij0 = B[ldb * i + j];
            double Bij1 = (j + 1 < n2) ? B[ldb * i + j + 1] : 0.0;
            for (k = j + 1; k < n2; k++) {
                B[ldb * i + k] -= A[k * lda + j] * Bij0;
                if (j + 1 < n2) {
                    B[ldb * i + k] -= A[k * lda + (j+1)] * Bij1;
                }
            }
        }
    }
}
}
