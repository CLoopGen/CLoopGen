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
for (i = 0; i < N; i++) {
    float tmp = X[i * incX];
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    for (j = j_min; j < j_max; j++) {
        const int a_index = (i - j) + lda * j;
        const int x_index = j * incX;
        const float Aji = A[a_index];
        tmp -= Aji * X[x_index];
    }
    if (nonunit) {
        X[i * incX] = tmp / A[lda * i];
    } else {
        X[i * incX] = tmp;
    }
}
}
