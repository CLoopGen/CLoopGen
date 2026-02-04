#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double tmp = alpha * X[i * incX];
    int base_j = i * incX;
    for (j = i; j < N; j++) {
        A[lda * i + j] += X[base_j + (j - i) * incX] * tmp;
    }
}
}
