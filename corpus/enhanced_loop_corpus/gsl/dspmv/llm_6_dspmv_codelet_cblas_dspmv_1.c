#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = beta;
    for (i = 0; i < N; i++) {
        Y[iy] = Y[iy] * temp;
        temp = Y[iy]; // Introduce WAW and RAW loop-carried dependency: temp depends on previous Y[iy]
        iy += incY;
    }
}
