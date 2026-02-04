#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < lenY; i++) {
        temp = Y[iy] * beta;
        Y[iy] = temp;
        iy += incY;
    }
}
