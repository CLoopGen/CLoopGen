#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int stride_x = incX;
const int stride_y = incY;
int base_x = 0;
for (i = 0; i < M; i++) {
    const double tmp = alpha * X[base_x];
    int base_a = i * lda;
    for (j = 0; j < N; j++) {
        A[base_a + j] += Y[j * stride_y] * tmp;
    }
    base_x += stride_x;
}
}
