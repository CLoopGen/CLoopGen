#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_X = (float*)malloc(N * sizeof(float));
if (!local_X) return;
for (i = 0; i < N; i++) {
    local_X[i] = X[i * incX]; 
}
for (i = 0; i < N; i++) {
    float tmp = local_X[i];
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    for (j = j_min; j < j_max; j++) {
        const float Aij = A[lda * i + (K + j - i)];
        tmp -= Aij * local_X[j];
    }
    if (nonunit) {
        local_X[i] = tmp / A[lda * i + K];
    } else {
        local_X[i] = tmp;
    }
}
for (i = 0; i < N; i++) {
    X[i * incX] = local_X[i];
}
free(local_X);
}
