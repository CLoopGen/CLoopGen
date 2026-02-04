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
    float prev_Bij = 0.0f;
    for (j = 0; j < n2; j++) {
        float current_Bij = B[ldb * i + j];
        if (nonunit && j > 0) {
            float Ajj = A[lda * (j-1) + (j-1)];
            B[ldb * i + j] /= Ajj;
        }
        for (k = j + 1; k < n2; k++) {
            B[ldb * i + k] -= A[(j-1) * lda + k] * prev_Bij;
        }
        prev_Bij = current_Bij;
    }
}
}
