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
    for (i = 0; i < N; i += 2) {
        for (int j = 0; j < 2 && (i + j) < N; j++) {
            const int idx = i + j;
            const int ixx = ix + j * incX;
            const int iyy = iy + j * incY;
            const double x = X[ixx];
            const double y = Y[iyy];
            X[ixx] = c * x + s * y;
            Y[iyy] = -s * x + c * y;
        }
        ix += 2 * incX;
        iy += 2 * incY;
    }
}
