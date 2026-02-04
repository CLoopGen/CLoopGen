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
for (i = 0; i < N; i++) {
    int base_index = (((i) * (2 * N - i + 1)) / 2);
    double temp = 0.0;
    int jx = ix;
    for (j = i; j < N; j++) {
        double atmp = Ap[base_index + (j - i)];
        temp += (nonunit || j == i ? atmp : 1.0) * X[jx];
        jx += incX;
    }
    X[ix] = temp;
    ix += incX;
}
}
