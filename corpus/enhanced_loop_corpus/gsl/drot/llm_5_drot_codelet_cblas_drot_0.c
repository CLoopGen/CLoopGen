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
    double temp_x, temp_y;
    temp_x = c * x + s * y;
    temp_y = -s * x + c * y;

    if (i % 2 == 0) {
        X[ix] = temp_x;
        Y[iy] = temp_y;
    } else {
        X[ix] = temp_y;
        Y[iy] = temp_x;
    }
    ix += incX;
    iy += incY;
}
}
