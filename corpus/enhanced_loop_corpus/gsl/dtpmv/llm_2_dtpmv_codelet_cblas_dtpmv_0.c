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
    int base_idx = ((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2;
    double atmp = Ap[base_idx];
    double temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = ((incX) > 0 ? i + 1 : (N - 1) - i) * incX;
    for (j = i + 1; j < N; j++) {
        atmp = Ap[base_idx + (j - i)];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix += incX;
}
}
