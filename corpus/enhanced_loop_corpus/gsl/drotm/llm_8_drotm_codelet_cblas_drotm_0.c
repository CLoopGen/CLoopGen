#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int n;
extern int i;
extern int j;
extern double h11;
extern double h21;
extern double h12;
extern double h22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < N; n += 2) {
    const double w1 = X[i];
    const double z1 = Y[j];
    X[i] = h11 * w1 + h12 * z1;
    Y[j] = h21 * w1 + h22 * z1;
    i += incX;
    j += incY;

    if (n + 1 < N) {
        const double w2 = X[i];
        const double z2 = Y[j];
        X[i] = h11 * w2 + h12 * z2;
        Y[j] = h21 * w2 + h22 * z2;
        i += incX;
        j += incY;
    }
}
}
