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
    double temp_x, temp_y;
    for (n = 0; n < N; n++) {
        const double w = X[i];
        const double z = Y[j];
        temp_x = h11 * w + h12 * z;
        temp_y = h21 * w + h22 * z;
        X[i] = temp_x;
        Y[j] = temp_y;
        i += incX;
        j += incY;
    }
}
