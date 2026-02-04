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
for (i = N; i > 0 && i--;) {
    int base_idx = (i * (i + 1)) / 2;
    float atmp = Ap[base_idx + i];
    float temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = (incX > 0 ? 0 : (N - 1) * (-incX));
    for (j = 0; j < i; j++) {
        atmp = Ap[base_idx + j];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix -= incX;
}
}
