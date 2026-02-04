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
    double *Bi = &B[i * ldb];
    for (j = 0; j < n2; j++) {
        if (nonunit) {
            double Ajj = A[j * lda + j];
            Bi[j] /= Ajj;
        }
        double Bij = Bi[j];
        double *Ak = &A[(j + 1) * lda + j];
        for (k = j + 1; k < n2; k++) {
            Bi[k] -= Ak[(k - j - 1) * lda] * Bij;
        }
    }
}
}
