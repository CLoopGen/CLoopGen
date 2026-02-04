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
    int base_idx = (((i) * (2 * N - i + 1)) / 2);
    float atmp = Ap[base_idx];
    float temp = (nonunit ? X[ix] * atmp : X[ix]);
    int jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        atmp = Ap[base_idx + (j - i)];
        temp += atmp * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix += incX;
}
}
