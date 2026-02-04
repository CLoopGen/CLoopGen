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
    int temp_iy = iy;
    for (i = 0; i < lenY; i++) {
        (((double *)Y)[2 * temp_iy]) = 0.;
        (((double *)Y)[2 * temp_iy + 1]) = 0.;
        temp_iy += incY;
    }
    iy = temp_iy;
}
