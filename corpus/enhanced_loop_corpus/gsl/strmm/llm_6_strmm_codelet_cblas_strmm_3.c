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
            float temp = 0.0f;
            // Introduce a new dependency: use previous j iteration's result in current
            // This creates a loop-carried dependency across j (RAW)
            if (j > 0) {
                temp = B[i * ldb + j - 1]; // Use prior value as base
            }
            if (nonunit) {
                temp += A[i * lda + i] * B[i * ldb + j];
            } else {
                temp += B[i * ldb + j];
            }
            for (k = i + 1; k < n1; k++) {
                temp += A[lda * k + i] * B[k * ldb + j];
            }
            B[ldb * i + j] = alpha * temp;
        }
    }
}
