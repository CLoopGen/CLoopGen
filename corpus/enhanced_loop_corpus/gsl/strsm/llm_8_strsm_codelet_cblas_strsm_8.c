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
    for (j = 0; j < n2; j += 2) {
        if (nonunit && j + 1 < n2) {
            float Ajj0 = A[lda * j + j];
            float Ajj1 = A[lda * (j+1) + (j+1)];
            B[ldb * i + j] /= Ajj0;
            B[ldb * i + j + 1] /= Ajj1;
        }
        {
            float Bij0 = B[ldb * i + j];
            float Bij1 = (j + 1 < n2) ? B[ldb * i + j + 1] : 0.0f;
            for (k = j + 1; k < n2; k++) {
                B[ldb * i + k] -= A[j * lda + k] * Bij0;
                if (j + 1 < n2) {
                    B[ldb * i + k] -= A[(j+1) * lda + k] * Bij1;
                }
            }
        }
    }
}
}
