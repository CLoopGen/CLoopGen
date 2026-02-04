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
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        float temp = 0.;
        const float *a_i = &A[i * lda];
        const float *a_j = &A[j * lda];
        for (k = 0; k < K; k++) {
            temp += a_i[k] * a_j[k];
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
