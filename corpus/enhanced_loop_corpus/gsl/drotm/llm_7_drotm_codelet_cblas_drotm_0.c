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
    double prev_w = 0.0, prev_z = 0.0;
    for (n = 0; n < N; n++) {
        const double w = X[i] + prev_w; // Introduce RAW dependency: current read depends on previous iteration
        const double z = Y[j] + prev_z; // Introduce RAW dependency
        prev_w = h11 * w + h12 * z;
        prev_z = h21 * w + h22 * z;
        X[i] = prev_w;
        Y[j] = prev_z;
        i += incX;
        j += incY;
    }
}
