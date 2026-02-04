#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_val = 0;
    for (i = 0; i < lenY; i++) {
        temp_val += incY;
        (((double *)Y)[2 * (iy + temp_val - incY)]) = 0.;
        (((double *)Y)[2 * (iy + temp_val - incY) + 1]) = 0.;
    }
    iy += lenY * incY;
}
