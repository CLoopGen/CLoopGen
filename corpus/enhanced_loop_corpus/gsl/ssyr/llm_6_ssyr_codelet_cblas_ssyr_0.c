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
    float temp_accum[N];
    for (i = 0; i < N; i++) {
        temp_accum[i] = alpha * X[ix];
        ix += incX;
    }
    for (i = 0; i < N; i++) {
        int jx = i * incX;
        for (j = i; j < N; j++) {
            A[lda * i + j] += X[jx] * temp_accum[i];
            jx += incX;
        }
    }
}
