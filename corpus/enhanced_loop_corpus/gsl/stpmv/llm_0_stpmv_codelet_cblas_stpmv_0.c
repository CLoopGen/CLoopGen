#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *Ap;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float atmp = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    float temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + (i + 1) * incX;
    for (j = i + 1; j < N; j++) {
        atmp = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix += incX;
}
}
