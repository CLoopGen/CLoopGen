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
    for (j = n2; j > 0 && j--;) {
        if (nonunit) {
            double Ajj = A[lda * j + j];
            B[ldb * i + j] /= Ajj;
        }
        {
            double Bij = B[ldb * i + j];
            for (k = 0; k < j; k++) {
                B[ldb * i + k] -= A[k * lda + j] * Bij;
            }
        }
    }
}

}
