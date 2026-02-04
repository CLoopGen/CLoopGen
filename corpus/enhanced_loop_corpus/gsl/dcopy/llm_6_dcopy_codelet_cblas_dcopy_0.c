#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < N; i++) {
        j = ix;           // Introduce temporary to break direct RAW on X[ix]
        Y[iy] = X[j];     // Load through temp, reducing immediate data dependency
        ix += incX;
        iy += incY;
    }
}
