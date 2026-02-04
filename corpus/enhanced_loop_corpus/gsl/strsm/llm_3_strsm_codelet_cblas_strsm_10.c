#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *A;
extern  int lda;
extern float *B;
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
    float *Bi = &B[ldb * i]; // Base pointer for row i of B
    for (j = n2; j > 0 && j--;) {
        if (nonunit) {
            float Ajj = A[lda * j + j];
            Bi[j] /= Ajj;
        }
        float Bij = Bi[j];
        float *Ak = &A[lda * j]; // Strided column access via row pointers in A
        for (k = 0; k < j; k++) {
            Bi[k] -= Ak[k] * Bij; // Consecutive access to A's column via precomputed offset
        }
    }
}
}
