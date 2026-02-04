#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = (i + 1 < N) ? alpha * X[ix + incX] : 0.0;
    int jx1 = ix;
    int jx2 = ix + incX;
    for (j = i; j < N; j++) {
        Ap[((((i) * (2 * N - i + 1)) / 2) + (j - i))] += X[jx1] * tmp1;
        if (i + 1 < N) {
            Ap[((((i + 1) * (2 * N - (i + 1) + 1)) / 2) + (j - i - 1))] += X[(j >= i+1) ? jx2 + (j - i - 1)*incX : jx2] * tmp2;
        }
    }
    ix += 2 * incX;
}
}
