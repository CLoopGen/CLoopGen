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
for (i = 0; i < n1; i += 2) {
    for (j = n2; j > 0; j--) {
        if (nonunit) {
            float Ajj = A[lda * j + j];
            if (Ajj != 0.0f) {
                B[ldb * i + j] /= Ajj;
                if (i + 1 < n1) {
                    B[ldb * (i + 1) + j] /= Ajj;
                }
            }
        }
        float Bij0 = B[ldb * i + j];
        float Bij1 = (i + 1 < n1) ? B[ldb * (i + 1) + j] : 0.0f;
        for (k = 0; k < j; k++) {
            B[ldb * i + k] -= A[j * lda + k] * Bij0;
            if (i + 1 < n1) {
                B[ldb * (i + 1) + k] -= A[j * lda + k] * Bij1;
            }
        }
    }
}
}
