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
    double temp = 0.;
    for (i = 0; i < lenY; i++) {
        Y[iy] = temp;
        temp = Y[iy];  // Introduce RAW dependency: read after write to same element
        iy += incY;
    }
}
