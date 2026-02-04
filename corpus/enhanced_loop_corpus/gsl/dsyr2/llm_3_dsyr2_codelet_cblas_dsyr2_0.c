#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_X = (int*)malloc(N * sizeof(int));
int *index_Y = (int*)malloc(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    index_X[idx] = idx * incX;
    index_Y[idx] = idx * incY;
}
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[index_X[i]];
    const double tmp2 = alpha * Y[index_Y[i]];
    for (j = i; j < N; j++) {
        A[lda * i + j] += tmp1 * Y[index_Y[j]] + tmp2 * X[index_X[j]];
    }
}
free(index_X);
free(index_Y);
}
