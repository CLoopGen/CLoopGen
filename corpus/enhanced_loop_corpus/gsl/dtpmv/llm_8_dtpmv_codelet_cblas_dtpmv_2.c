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
for (i = N; i > 0 && i--;) {
    double atmp = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    double temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j += 2) {
        if (j + 1 < i) {
            double atmp1 = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
            double atmp2 = Ap[((((((j + 1) - 1) + 1) * (2 * (N) - ((j + 1) - 1))) / 2) + (i) - (j + 1))];
            temp += atmp1 * X[jx] + atmp2 * X[jx + incX];
            jx += 2 * incX;
        } else {
            atmp = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
            temp += atmp * X[jx];
            jx += incX;
        }
    }
    X[ix] = temp;
    ix -= incX;
}
}
