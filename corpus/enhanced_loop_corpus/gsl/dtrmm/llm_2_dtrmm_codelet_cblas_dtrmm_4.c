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
    for (j = n2 - 1; j >= 0; j--) {
        double temp = 0.;
        double *Ap = &A[lda * j];
        double *Bp = &B[i * ldb];
        for (k = 0; k < j; k++) {
            temp += Ap[k] * Bp[k];
        }
        if (nonunit) {
            temp += Ap[j] * Bp[j];
        } else {
            temp += Bp[j];
        }
        Bp[j] = alpha * temp;
    }
}
}
