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
    float *B_i = B + i * ldb;
    for (j = n2; j > 0; --j) {
        float temp = 0.0f;
        float *A_j = A + j;
        for (k = 0; k < j; k++) {
            temp += (*(A_j + lda * k)) * (*(B_i + k));
        }
        if (nonunit) {
            temp += (*(A_j + lda * j)) * (*(B_i + j));
        } else {
            temp += (*(B_i + j));
        }
        *(B_i + j) = alpha * temp;
    }
}
}
