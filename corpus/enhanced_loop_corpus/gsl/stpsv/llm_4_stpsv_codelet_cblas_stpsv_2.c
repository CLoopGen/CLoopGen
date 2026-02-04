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
for (i = 1; i < N; i++) {
    float tmp = X[ix];
    int jx = (incX > 0) ? 0 : (N - 1) * (-incX);
    for (j = 0; j < i; j++) {
        const float Aji = Ap[((j * (2 * N - j + 1)) / 2) + (i - j - 1)];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    X[ix] = nonunit ? (tmp / Ap[(i * (2 * N - i + 1)) / 2]) : tmp;
    ix += incX;
}
}
