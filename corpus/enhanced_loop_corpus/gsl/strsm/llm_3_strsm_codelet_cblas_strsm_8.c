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
// Change memory access to simulate transposed-like traversal by flipping index roles in B (interchange effect)
// Access B in column-major order even if storage is row-major, increasing stride for better cache simulation stress
for (j = 0; j < n2; j++) {
    if (nonunit) {
        float Ajj = A[lda * j + j];
        for (i = 0; i < n1; i++) {
            B[ldb * i + j] /= Ajj;  // Column j of B accessed with stride ldb (consecutive per column)
        }
    }
    for (i = 0; i < n1; i++) {
        float Bij = B[ldb * i + j];
        for (k = j + 1; k < n2; k++) {
            // Update subsequent elements in the same row of B, but now k-loop remains inner
            B[ldb * i + k] -= A[j * lda + k] * Bij;
        }
    }
}
}
