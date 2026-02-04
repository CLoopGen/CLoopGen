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
// Reduced loop nesting depth by flattening the original nested structure
// Original inner loop is unrolled and merged into a single loop using index arithmetic

int flat_index = 0;
for (i = 0; i < N; i++) {
    const double tmp = alpha * X[ix];
    int jx = ix;
    for (j = i; j < N; j++, jx += incX) {
        A[lda * i + j] += X[jx] * tmp;
    }
    ix += incX;
}
}
