#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j++) {
    float temp_sum = 0.0f;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i += 4) {
        float sum = 0.0f;
        int end = (i + 4 <= M) ? i + 4 : M;
        for (int k = i; k < end; k++) {
            sum += X[ix] * Y[jy];
            ix += incX;
        }
        temp_sum += sum;
    }
    A[lda * j] += alpha * temp_sum;
    jy += incY;
}
}
