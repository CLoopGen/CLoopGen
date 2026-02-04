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
    float tmp = X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j += 2) {
        if (j + 1 < i) {
            const float Aji1 = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
            const float Aji2 = Ap[((((((j+1) - 1) + 1) * (2 * (N) - ((j+1) - 1))) / 2) + (i) - (j+1))];
            tmp -= Aji1 * X[jx] + Aji2 * X[jx + incX];
            jx += 2 * incX;
        } else {
            const float Aji = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
            tmp -= Aji * X[jx];
            jx += incX;
        }
    }
    if (nonunit) {
        X[ix] = tmp / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
