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
    int jx = ix;
    for (j = i; j < N; j++) {
        if (X[jx] != 0.0f) {
            A[lda * i + j] += X[jx] * tmp;
        }
        jx += incX;
    }
    ix += incX;
}
}
