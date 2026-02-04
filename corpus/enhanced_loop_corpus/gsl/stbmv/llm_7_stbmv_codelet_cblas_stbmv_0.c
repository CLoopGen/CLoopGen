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
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_X = (float*)malloc(N * sizeof(float));
if (!local_X) return;
for (i = 0; i < N; i++) {
    local_X[i] = X[i * incX]; // Decouple write dependency by using local copy
}
for (i = 0; i < N; i++) {
    float temp = (nonunit ? A[lda * i + 0] : 1.) * local_X[i];
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += local_X[j] * A[lda * i + (j - i)];
    }
    X[ix] = temp;
    ix += incX;
}
free(local_X);
}
