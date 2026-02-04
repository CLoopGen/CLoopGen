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
    for (i = 0; i < lenY && iy < lenY * incY; i++) {
        double *ptr = (double *)Y + 2 * iy;
        *ptr = 0.0;
        *(ptr + 1) = 0.0;
        iy += incY;
    }
}
