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
for (i = N - (N % 4); i > 0 && i--;) {
    double atmp = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    double temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i - (i % 4); j += 4) {
        temp += Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))] * X[jx]
               + Ap[((((((j+1) - 1) + 1) * (2 * (N) - ((j+1) - 1))) / 2) + (i) - (j+1))] * X[jx + incX]
               + Ap[((((((j+2) - 1) + 1) * (2 * (N) - ((j+2) - 1))) / 2) + (i) - (j+2))] * X[jx + 2*incX]
               + Ap[((((((j+3) - 1) + 1) * (2 * (N) - ((j+3) - 1))) / 2) + (i) - (j+3))] * X[jx + 3*incX];
        jx += 4 * incX;
    }
    for (; j < i; j++) {
        atmp = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix -= incX;
}
}
