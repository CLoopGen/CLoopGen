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
    const int idx_x = i + n * incX;
    const int idx_y = j + n * incY;
    const double w = X[idx_x];
    const double z = Y[idx_y];
    X[idx_x] = h11 * w + h12 * z;
    Y[idx_y] = h21 * w + h22 * z;
}
}
