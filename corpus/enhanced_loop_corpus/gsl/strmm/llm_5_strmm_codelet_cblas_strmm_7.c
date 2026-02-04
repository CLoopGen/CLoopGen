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
for (i = 0; i < n1; i++) {
    for (j = n2 - 1; j >= 0; j--) {
        float temp = 0.;
        int limit = j + (nonunit ? 1 : 0);
        for (k = 0; k <= limit; k++) {
            if (k < j) {
                temp += A[lda * j + k] * B[i * ldb + k];
            } else if (k == j) {
                temp += (nonunit ? A[j * lda + j] * B[i * ldb + j] : B[i * ldb + j]);
            }
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
