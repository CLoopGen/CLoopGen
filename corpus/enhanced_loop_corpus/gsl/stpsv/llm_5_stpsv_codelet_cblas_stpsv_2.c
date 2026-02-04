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
    int jx = 0;
    if (incX <= 0) {
        jx = (N - 1) * (-incX);
    }
    j = 0;
    if (i > 0) {
        do {
            const float Aji = Ap[(((j) * (2 * N - j + 1)) / 2) + (i - j - 1)];
            tmp -= Aji * X[jx];
            jx += incX;
            j++;
        } while (j < i);
    }
    if (nonunit) {
        float diag = Ap[(i * (2 * N - i + 1)) / 2];
        X[ix] = tmp / diag;
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
