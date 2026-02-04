#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        float temp = 0.;
        for (k = 0; k < K; k++) {
            temp += A[i + k * lda] * A[j + k * lda];
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
