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
double temp_accum[N]; // Introduce local accumulation array to remove immediate write-after-read dependency
for (i = 0; i < N; i++) {
    temp_accum[i] = 0.0;
}
for (i = 1; i < N; i++) {
    double tmp = X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j++) {
        const double Aji = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    temp_accum[i] = tmp; // Store intermediate result to break WAW and WAR dependencies on X[ix]
}
// Update X in a separate sequential pass to eliminate loop-carried dependencies
int update_ix = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + incX; // Start from first modified index
for (i = 1; i < N; i++) {
    if (nonunit) {
        X[update_ix] = temp_accum[i] / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    } else {
        X[update_ix] = temp_accum[i];
    }
    update_ix += incX;
}
}
