#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < lenY * 2; i += 2) {
        Y[iy] = 0.;
        if (i + 1 < lenY) {
            Y[iy + incY] = 0.;
        }
        iy += incY;
    }
}
