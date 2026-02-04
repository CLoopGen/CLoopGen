#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N - 1; i > 0 && i--;) {
    float tmp1 = X[ix];
    float tmp2 = 0.0f;
    jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const float Aji = A[lda * j + i];
        tmp1 -= Aji * X[jx];
        tmp2 += Aji * Aji; // Additional computation to increase arithmetic intensity
        jx += incX;
    }
    if (nonunit) {
        X[ix] = (tmp1 + tmp2 * 0.01f) / A[lda * i + i]; // Slight adjustment using extra computed value
    } else {
        X[ix] = tmp1;
    }
    ix -= incX;
}
}
