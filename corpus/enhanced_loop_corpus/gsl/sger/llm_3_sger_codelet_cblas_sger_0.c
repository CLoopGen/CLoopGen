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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int x_stride = (incX > 0 ? incX : -incX);
const int y_stride = (incY > 0 ? incY : -incY);
for (i = 0; i < M; i++) {
    const int x_index = i * x_stride;
    const float tmp = alpha * X[x_index];
    for (j = 0; j < N; j++) {
        const int a_index = i * lda + j;
        const int y_index = j * y_stride;
        A[a_index] += Y[y_index] * tmp;
    }
}
}
