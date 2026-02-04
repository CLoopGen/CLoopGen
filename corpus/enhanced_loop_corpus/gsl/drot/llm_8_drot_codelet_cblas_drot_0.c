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
    X[ix] = c * x + s * y;
    Y[iy] = -s * x + c * y;
    // Unrolled to process two iterations per loop cycle, doubling computational intensity
    if (i + 1 < N) {
        const double x2 = X[ix + incX];
        const double y2 = Y[iy + incY];
        X[ix + incX] = c * x2 + s * y2;
        Y[iy + incY] = -s * x2 + c * y2;
        ix += 2 * incX;
        iy += 2 * incY;
        i++;
    } else {
        ix += incX;
        iy += incY;
    }
}
}
