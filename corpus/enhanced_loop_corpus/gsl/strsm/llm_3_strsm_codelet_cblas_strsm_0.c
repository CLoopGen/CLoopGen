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
ptrdiff_t offset_A, offset_B;
for (i = n1; i > 0 && i--;) {
    offset_B = (ptrdiff_t)i * ldb;
    if (nonunit) {
        offset_A = (ptrdiff_t)i * (lda + 1);
        float Aii = A[offset_A];
        for (j = 0; j < n2; j++) {
            B[offset_B + j] /= Aii;
        }
    }
    for (k = 0; k < i; k++) {
        offset_A = (ptrdiff_t)k * lda + i;
        const float Aki = A[offset_A];
        for (j = 0; j < n2; j++) {
            B[(ptrdiff_t)k * ldb + j] -= Aki * B[offset_B + j];
        }
    }
}
}
