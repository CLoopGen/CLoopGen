#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern  double c;
extern  double s;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double x = X[ix];
    const double y = Y[iy];
    if (x != 0 || y != 0) {
        X[ix] = c * x + s * y;
        Y[iy] = -s * x + c * y;
    }
    ix += incX;
    iy += incY;
}
}
