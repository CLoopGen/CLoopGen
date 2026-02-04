#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
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
    for (j = 0; j < n2; j++) {
        for (int ii = 0; ii < 2 && (i + ii) < n1; ii++) {
            float temp = 0.;
            int row = i + ii;
            if (nonunit) {
                temp = A[j * lda + j] * B[row * ldb + j];
            } else {
                temp = B[row * ldb + j];
            }
            for (k = j + 1; k < n2; k++) {
                temp += A[lda * k + j] * B[row * ldb + k];
            }
            B[ldb * row + j] = alpha * temp;
        }
    }
}
}
