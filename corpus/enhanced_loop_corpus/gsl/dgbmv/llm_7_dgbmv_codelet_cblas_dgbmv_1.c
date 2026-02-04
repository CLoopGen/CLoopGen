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
    double prev = 1.0;
    for (i = 0; i < lenY; i++) {
        if (i > 0) {
            Y[iy] *= beta + prev;
        } else {
            Y[iy] *= beta;
        }
        prev = Y[iy];
        iy += incY;
    }
}
