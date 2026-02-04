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
    for (j = i; j < N; j++) {
        float temp = 0.;
        const float *a_i = &A[i * lda];
        const float *a_j = &A[j * lda];
        for (k = 0; k < K; k += 2) {
            if (k + 1 < K) {
                temp += a_i[k] * a_j[k] + a_i[k+1] * a_j[k+1];
            } else {
                temp += a_i[k] * a_j[k];
            }
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
