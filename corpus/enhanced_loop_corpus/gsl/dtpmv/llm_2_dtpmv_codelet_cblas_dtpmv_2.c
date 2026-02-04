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
    ptrdiff_t aidx = ((i * (2 * N - i + 1)) / 2) - 1;
    double atmp = Ap[aidx];
    double temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = (incX > 0 ? 0 : (N - 1) * (-incX));
    for (j = 0; j < i; j++) {
        ptrdiff_t inner_aidx = (((j + 1) * (2 * N - j)) / 2) + (i - j - 1);
        atmp = Ap[inner_aidx];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix -= incX;
}
}
