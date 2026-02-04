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
for (i = 0; i < N; i++) {
    double atmp = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    double temp = X[ix] * (nonunit ? atmp : 1.0);
    int jx = ((incX) > 0 ? (i + 1) * incX : ((N) - 1) * (-(incX)) + (i + 1) * incX);
    for (j = i + 1; j < N; j++) {
        atmp = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix += incX;
}
}
