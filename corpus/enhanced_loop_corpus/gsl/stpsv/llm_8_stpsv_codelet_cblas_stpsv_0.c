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
        const float Aij1 = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        tmp1 -= Aij1 * X[jx];
        jx += incX;
        if (j + 1 < N) {
            const float Aij2 = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j + 1) - (i))];
            tmp2 -= Aij2 * X[jx];
            jx += incX;
        }
    }
    tmp1 += tmp2;
    if (nonunit) {
        X[ix] = tmp1 / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    } else {
        X[ix] = tmp1;
    }
    ix -= incX;
}
}
