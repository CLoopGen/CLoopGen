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
for (j = 0; j < n2; j++) {
    int aj_base = j * lda;
    int bj_base = j * ldb;
    for (i = 0; i < n1; i++) {
        float temp = 0.;
        int b_index = i * ldb + j;
        if (nonunit) {
            temp = A[aj_base + j] * B[b_index];
        } else {
            temp = B[b_index];
        }
        for (k = j + 1; k < n2; k++) {
            temp += A[aj_base + k] * B[i * ldb + k];
        }
        B[b_index] = alpha * temp;
    }
}
}
