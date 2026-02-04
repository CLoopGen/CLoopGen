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
double *local_X = (double*)malloc(N * sizeof(double));
if (!local_X) return;
for (i = 0; i < N; i++) {
    int offset = (((i) * (2 * N - i + 1)) / 2);
    local_X[i] = X[ix];
    double temp = (nonunit ? X[ix] * Ap[offset] : X[ix]);
    for (j = i + 1; j < N; j++) {
        double atmp = Ap[offset + (j - i)];
        int jx = ((incX > 0 ? 0 : (N - 1) * (-incX))) + j * incX;
        temp += atmp * X[jx];
    }
    X[ix] = temp;
    ix += incX;
}
free(local_X);
}
