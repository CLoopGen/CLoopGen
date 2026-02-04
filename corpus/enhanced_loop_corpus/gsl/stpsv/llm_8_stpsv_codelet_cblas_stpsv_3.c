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
for (i = N - 1; i > 0 && i--;) {
    float tmp1 = X[ix];
    float tmp2 = 0.0f;
    int jx = ix + incX;
    for (j = i + 1; j < N; j += 2) {
        const float Aji1 = Ap[(((j) * ((j) + 1)) / 2 + (i))];
        tmp1 -= Aji1 * X[jx];
        jx += incX;
        if (j + 1 < N) {
            const float Aji2 = Ap[(((j+1) * ((j+1) + 1)) / 2 + (i))];
            tmp2 -= Aji2 * X[jx];
            jx += incX;
        }
    }
    tmp1 += tmp2;
    if (nonunit) {
        X[ix] = tmp1 / Ap[(((i) * ((i) + 1)) / 2 + (i))];
    } else {
        X[ix] = tmp1;
    }
    ix -= incX;
}
}
