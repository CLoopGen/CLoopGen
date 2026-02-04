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
// Change memory access pattern to use pointer-based, consecutive access
// to enhance cache performance and enable better compiler optimization

for (i = 0; i < n1; i++) {
    if (nonunit) {
        float Aii = A[lda * i + i];
        float *Bi = &B[ldb * i];  // Base pointer for row i of B
        for (j = 0; j < n2; j++) {
            Bi[j] /= Aii;  // Consecutive access via pointer
        }
    }
    for (k = i + 1; k < n1; k++) {
        const float Aki = A[k * lda + i];
        float *Bk = &B[ldb * k];  // Row k of B
        float *Bi = &B[ldb * i];  // Row i of B
        for (j = 0; j < n2; j++) {
            Bk[j] -= Aki * Bi[j];  // Consecutive, aligned accesses
        }
    }
}
}
