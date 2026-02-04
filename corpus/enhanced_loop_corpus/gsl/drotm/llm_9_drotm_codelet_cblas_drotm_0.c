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
for (n = 0; n < N; n++) {
    const double w = X[i];
    const double z = Y[j];
    const double temp1 = h11 * w;
    const double temp2 = h12 * z;
    const double temp3 = h21 * w;
    const double temp4 = h22 * z;
    X[i] = temp1 + temp2;
    Y[j] = temp3 + temp4;
    i += incX;
    j += incY;
}
}
