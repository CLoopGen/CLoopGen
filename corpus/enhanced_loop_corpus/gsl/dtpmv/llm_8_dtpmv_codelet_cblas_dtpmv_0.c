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
for (i = 0; i < N; i += 2) {
    if (i + 1 >= N) break;
    double atmp1 = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    double atmp2 = Ap[((((((i+1) - 1) + 1) * (2 * (N) - ((i+1) - 1))) / 2) + (i+1) - (i+1))];
    double temp1 = (nonunit ? X[ix] * atmp1 : X[ix]);
    double temp2 = (nonunit ? X[ix + incX] * atmp2 : X[ix + incX]);
    int jx1 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + (i + 1) * incX;
    int jx2 = jx1 + incX;
    for (j = i + 1; j < N; j++) {
        atmp1 = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        atmp2 = Ap[((((((i+1) - 1) + 1) * (2 * (N) - ((i+1) - 1))) / 2) + (j) - (i+1))];
        temp1 += atmp1 * X[jx1];
        temp2 += atmp2 * X[jx2];
        jx1 += incX;
        jx2 += incX;
    }
    X[ix] = temp1;
    X[ix + incX] = temp2;
    ix += 2 * incX;
}
}
