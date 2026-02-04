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
    // Variant 1: Modified memory access pattern using strided access with precomputed base pointers
    double *Bi;
    for (i = n1; i > 0 && i--;) {
        Bi = B + ldb * i;
        if (nonunit) {
            double Aii = A[lda * i + i];
            for (j = 0; j < n2; j++) {
                Bi[j] /= Aii;
            }
        }
        for (k = 0; k < i; k++) {
            const double Aik = A[i * lda + k];
            double *Bk = B + ldb * k;
            for (j = 0; j < n2; j++) {
                Bk[j] -= Aik * Bi[j];
            }
        }
    }
}
