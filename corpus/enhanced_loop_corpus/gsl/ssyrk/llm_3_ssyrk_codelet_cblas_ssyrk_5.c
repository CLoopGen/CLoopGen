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
for (k = 0; k < K; k++) {
    float *a_row = &A[k * lda];
    for (i = 0; i < N; i++) {
        float a_ik = a_row[i];
        for (j = i; j < N; j++) {
            C[i * ldc + j] += alpha * a_ik * a_row[j];
        }
    }
}
}
