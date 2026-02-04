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
    double prev_c = c, prev_s = s;
    double temp_c = c, temp_s = s;
    for (i = 0; i < N; i++) {
        if (i > 0) {
            temp_c = prev_c * 0.99; // introduce loop-carried dependency on c
            temp_s = prev_s * 1.01; // and on s
        }
        const double x = X[ix];
        const double y = Y[iy];
        X[ix] = temp_c * x + temp_s * y;
        Y[iy] = -temp_s * x + temp_c * y;
        prev_c = temp_c;
        prev_s = temp_s;
        ix += incX;
        iy += incY;
    }
}
