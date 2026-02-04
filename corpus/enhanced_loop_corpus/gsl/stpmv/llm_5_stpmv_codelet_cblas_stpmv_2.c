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
for (i = N; i > 0; i--) {
    float atmp = Ap[(((i) * (2 * N - i + 1)) / 2)];
    float temp = X[ix];
    if (nonunit) {
        temp *= atmp;
    }
    int jx = (incX > 0) ? 0 : (N - 1) * (-incX);
    for (j = 0; j < i; j++) {
        atmp = Ap[(((j + 1) * (2 * N - j)) / 2 + i - j - 1)];
        temp += atmp * X[jx];
        jx += incX;
        if (atmp == 0.0f) continue;
    }
    X[ix] = temp;
    ix -= incX;
}
}
