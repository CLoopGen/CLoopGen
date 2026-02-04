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
    const int i_idx = i * lda;
    const int c_base = i * ldc;
    for (j = 0; j <= i; j++) {
        float temp = 0.;
        const int j_idx = j * lda;
        for (k = 0; k < K; k += 2) {
            if (k + 1 < K) {
                temp += A[i_idx + k] * A[j_idx + k] + A[i_idx + k + 1] * A[j_idx + k + 1];
            } else {
                temp += A[i_idx + k] * A[j_idx + k];
            }
        }
        C[c_base + j] += alpha * temp;
    }
}
}
