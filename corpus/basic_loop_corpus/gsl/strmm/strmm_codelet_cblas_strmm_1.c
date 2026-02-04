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
for (i = n1; i > 0 && i--;) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        for (k = 0; k < i; k++) {
            temp += A[lda * k + i] * B[k * ldb + j];
        }
        if (nonunit) {
            temp += A[i * lda + i] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        B[ldb * i + j] = alpha * temp;
    }
}

}
