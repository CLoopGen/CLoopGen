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
        float tmp = X[ix];
        int jx = ix + incX;
        if (i + 1 < N) {
            for (j = i + 1; j < N; j++) {
                const float Aij = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
                tmp -= Aij * X[jx];
                jx += incX;
            }
        }
        if (nonunit) {
            float diag = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
            X[ix] = diag != 0.0f ? tmp / diag : tmp;
        } else {
            X[ix] = tmp;
        }
        ix -= incX;
    }
}
