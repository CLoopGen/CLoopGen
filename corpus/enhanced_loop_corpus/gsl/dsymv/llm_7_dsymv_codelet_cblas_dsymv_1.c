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
    double prev = 1.0;
    for (i = 0; i < N; i++) {
        double current = Y[iy] * beta * prev;
        Y[iy] = current;
        prev = current;
        iy += incY;
    }
}
