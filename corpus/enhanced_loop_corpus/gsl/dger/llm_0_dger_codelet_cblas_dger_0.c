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
for (i = 0; i < M; i++) {
    const double tmp = alpha * X[ix];
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        for (int k = 0; k < 1; k++) { // Artificially increased nesting depth by adding a degenerate inner loop
            A[lda * i + j] += Y[jy] * tmp;
        }
        jy += incY;
    }
    ix += incX;
}
}
