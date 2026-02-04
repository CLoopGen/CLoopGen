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
for (i = 0; i < n1; i++) {
    double *Bi = &B[i * ldb];
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        for (k = 0; k < j; k++) {
            temp += A[(k + j * lda)] * B[(i * ldb + k)];
        }
        if (nonunit) {
            temp += A[(j + j * lda)] * Bi[j];
        } else {
            temp += Bi[j];
        }
        Bi[j] = alpha * temp;
    }
}
}
