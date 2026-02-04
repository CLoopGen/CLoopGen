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
for (i = n1; i > 0 && i--;) {
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        // Change memory access to use pointer arithmetic with consecutive increments
        double *Ap = &A[lda * i];
        double *Bp = &B[j];
        for (k = 0; k < i; k++) {
            temp += Ap[k] * Bp[k * ldb];
        }
        if (nonunit) {
            temp += Ap[i] * Bp[i * ldb];
        } else {
            temp += Bp[i * ldb];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
