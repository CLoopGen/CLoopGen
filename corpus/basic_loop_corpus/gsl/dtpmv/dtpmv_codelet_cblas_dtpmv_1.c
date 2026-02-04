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
    for (j = 0; j < i; j++) {
        atmp = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix -= incX;
}

}
