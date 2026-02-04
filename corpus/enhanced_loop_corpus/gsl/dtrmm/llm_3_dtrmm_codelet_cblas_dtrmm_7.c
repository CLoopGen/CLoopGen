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
ptrdiff_t offset_A, offset_B;
for (i = 0; i < n1; i++) {
    for (j = n2; j > 0; --j) {
        double temp = 0.;
        ptrdiff_t base_B = i * (ptrdiff_t)ldb;
        for (k = 0; k < j; k++) {
            offset_A = j + k * (ptrdiff_t)lda;
            offset_B = k + base_B;
            temp += A[offset_A] * B[offset_B];
        }
        offset_A = j + j * (ptrdiff_t)lda;
        offset_B = j + base_B;
        if (nonunit) {
            temp += A[offset_A] * B[offset_B];
        } else {
            temp += B[offset_B];
        }
        B[offset_B] = alpha * temp;
    }
}
}
