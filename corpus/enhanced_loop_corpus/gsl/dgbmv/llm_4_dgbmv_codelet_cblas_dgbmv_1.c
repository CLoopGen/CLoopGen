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
    if (lenY <= 0) return;
    for (i = 0; i < lenY; i++) {
        if (beta == 1.0) continue;
        Y[iy] *= beta;
        iy += incY;
    }
}
