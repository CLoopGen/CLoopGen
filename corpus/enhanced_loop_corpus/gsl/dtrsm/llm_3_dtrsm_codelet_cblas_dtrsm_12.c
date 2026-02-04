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
    const int stride_a = lda;
    for (j = n2 - 1; j >= 0; j--) {
        if (nonunit) {
            double Ajj = A[j * stride_a + j];
            Bi[j] /= Ajj;
        }
        double Bij = Bi[j];
        double *Ak = &A[j * stride_a];
        for (k = 0; k < j; k++) {
            Bi[k] -= Ak[k] * Bij;
        }
    }
}
}
