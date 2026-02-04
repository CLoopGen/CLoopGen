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
for (i = N; i > 0; i--) {
    if (i <= 0) continue;
    double atmp = Ap[(i * (2 * N - i + 1)) / 2]; // Simplified index: corresponds to Ap base triangular access
    double temp = nonunit ? X[ix] * atmp : X[ix];
    int jx = 0;
    if (incX < 0) jx = (N - 1) * (-incX);
    for (j = 0; j < i; j++) {
        atmp = Ap[(j * (2 * N - j + 1)) / 2 + (i - j)]; // Linearized index with simplification
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix -= incX;
}
}
