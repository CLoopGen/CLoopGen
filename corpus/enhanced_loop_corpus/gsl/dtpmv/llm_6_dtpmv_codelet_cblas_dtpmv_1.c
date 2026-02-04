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
    double atmp = Ap[(((i) * ((i) + 1)) / 2 + (i))];
    double temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int k = 0;
    while (k < i) {  // Introducing a different control flow within the loop body using nested logic
        atmp = Ap[(((i) * ((i) + 1)) / 2 + k)];
        temp += atmp * X[jx];
        jx += incX;
        k++;
    }
    X[ix] = temp;
    ix -= incX;
}
}
