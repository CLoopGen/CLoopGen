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
if (lenY > 0) {
    for (i = 0; i < lenY; i++) {
        (((float *)Y)[2 * (iy)]) = 0.;
        (((float *)Y)[2 * (iy) + 1]) = 0.;
        iy += incY;
    }
}
}
