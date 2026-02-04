#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (i = 0; i < N; i++) {
        temp = Y[iy] + temp;  // Introduce RAW dependency: temp depends on previous iteration
        Y[iy] = 0.;
        iy += incY;
    }
}
