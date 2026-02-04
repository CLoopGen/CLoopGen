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
float prev_alpha = alpha;
for (i = 0; i < N; i++) {
    float local_alpha = prev_alpha + (i > 0 ? A[lda*(i-1) + (i-1)] * 0.01f : 0.0f);
    const float tmp = local_alpha * X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j <= i; j++) {
        float update = X[jx] * tmp;
        A[lda * i + j] = (A[lda * i + j] + update) * 0.99f;
        jx += incX;
    }
    prev_alpha = local_alpha;
    ix += incX;
}
}
