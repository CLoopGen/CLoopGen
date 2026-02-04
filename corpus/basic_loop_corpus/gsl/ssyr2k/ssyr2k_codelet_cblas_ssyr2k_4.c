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
        for (k = 0; k < K; k++) {
            temp += (A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k]);
        }
        C[i * ldc + j] += alpha * temp;
    }
}

}
