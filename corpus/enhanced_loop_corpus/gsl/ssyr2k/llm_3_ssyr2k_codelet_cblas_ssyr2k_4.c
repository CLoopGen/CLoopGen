#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *B;
extern  int ldb;
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
        ptrdiff_t a_offset = i * lda;
        ptrdiff_t b_offset_j = j * ldb;
        ptrdiff_t b_offset_i = i * ldb;
        ptrdiff_t a_offset_j = j * lda;
        for (k = 0; k < K; k++) {
            temp += (A[a_offset + k] * B[b_offset_j + k] + B[b_offset_i + k] * A[a_offset_j + k]);
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
