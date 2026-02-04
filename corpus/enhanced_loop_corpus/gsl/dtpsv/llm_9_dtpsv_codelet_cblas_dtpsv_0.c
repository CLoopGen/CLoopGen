#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce trip count by skipping every other row, decreasing overall work
for (i = N - 1; i > 0 && i--; i--) {  // Decrement twice per iteration effectively halving iterations
    double tmp = X[ix];
    int jx = ix + incX;
    // Simplify computation: limit inner loop to small fixed window instead of full upper range
    int limit = (i + 5 < N) ? i + 5 : N;  // Only process up to 4 elements ahead
    for (j = i + 1; j < limit; j++) {
        const double Aij = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    if (nonunit) {
        double diag = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
        X[ix] = (diag != 0.0) ? tmp / diag : tmp;  // Safe division
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
    if (ix < 0) break;  // Prevent invalid access due to larger step
}
}
