#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = N - 1; i > 0 && i--;) {
        double tmp = X[ix];
        int jx = ix + incX;
        double sum = 0.0;
        for (j = i + 1; j < N; j++) {
            const double Aji = Ap[(((j) * ((j) + 1)) / 2 + (i))];
            sum += Aji * X[jx];
            jx += incX;
        }
        tmp -= sum;
        if (nonunit) {
            X[ix] = tmp / Ap[(((i) * ((i) + 1)) / 2 + (i))];
        } else {
            X[ix] = tmp;
        }
        ix -= incX;
    }
}
