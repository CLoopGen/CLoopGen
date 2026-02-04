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
for (i = N - 1; i >= 0; i--) {
    if (i == 0) break;
    float tmp = X[ix];
    int jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const float Aji = Ap[(((j) * ((j) + 1)) / 2 + (i))];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit && Ap[(((i) * ((i) + 1)) / 2 + (i))] != 0.0f) {
        X[ix] = tmp / Ap[(((i) * ((i) + 1)) / 2 + (i))];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
