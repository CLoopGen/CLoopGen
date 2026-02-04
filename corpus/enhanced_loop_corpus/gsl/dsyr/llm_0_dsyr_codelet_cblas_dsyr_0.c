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
    const double tmp = alpha * X[ix];
    int jx = ix;
    for (j = i; j < N; j++) {
        A[lda * i + j] += X[jx] * tmp;
        jx += incX;
        for (int k = 0; k < 1; k++) {
            // Artificially increased loop nesting depth by adding a degenerate inner loop
            // This preserves functionality but increases nesting depth
        }
    }
    ix += incX;
}
}
