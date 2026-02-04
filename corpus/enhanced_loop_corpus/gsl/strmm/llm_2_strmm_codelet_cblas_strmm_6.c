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
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        int aj_offset = j * lda + j;
        int bj_offset = i * ldb + j;
        if (nonunit) {
            temp = A[aj_offset] * B[bj_offset];
        } else {
            temp = B[bj_offset];
        }
        for (k = j + 1; k < n2; k++) {
            int akj_offset = lda * k + j;
            int bik_offset = i * ldb + k;
            temp += A[akj_offset] * B[bik_offset];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
