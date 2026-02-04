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
for (i = N - 1; i >= 0; i--) {
    double tmp = X[ix];
    int jx = ix + incX;
    if (i < N - 2) {
        for (j = i + 1; j < N - 1; j++) {
            const double Aji = Ap[(((j) * ((j) + 1)) / 2 + (i))];
            const double Aji_next = Ap[(((j+1) * ((j+1) + 1)) / 2 + (i))];
            const double x_val = X[jx];
            const double x_next = X[jx + incX];
            tmp -= Aji * x_val + Aji_next * x_next;
            jx += 2 * incX;
            j++;
        }
        if (j == N - 1) {
            const double Aji = Ap[(((j) * ((j) + 1)) / 2 + (i))];
            tmp -= Aji * X[jx];
        }
    } else if (i == N - 2) {
        const double Aji = Ap[(((N-1) * ((N-1) + 1)) / 2 + (i))];
        tmp -= Aji * X[ix + incX + incX];
    }
    if (nonunit && Ap[(((i) * ((i) + 1)) / 2 + (i))] != 0.0) {
        X[ix] = tmp / Ap[(((i) * ((i) + 1)) / 2 + (i))];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
