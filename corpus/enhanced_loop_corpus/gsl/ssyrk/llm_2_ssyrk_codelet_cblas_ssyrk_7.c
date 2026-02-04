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
        const int a_offset_i = i * lda;
        const int a_offset_j = j * lda;
        const int c_offset = i * ldc + j;
        for (k = 0; k < K; k++) {
            temp += A[a_offset_i + k] * A[a_offset_j + k];
        }
        C[c_offset] += alpha * temp;
    }
}
}
