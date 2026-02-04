#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const float tmp = alpha * X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    float temp_sum = 0.0f;
    for (j = 0; j <= i; j++) {
        temp_sum += X[jx] * tmp;
        jx += incX;
    }
    A[lda * i + i] += temp_sum;
    ix += incX;
}
}
