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
for (i = 0; i < lenY; i++) {
    for (int k = 0; k < 1; k++) {
        (((double *)Y)[2 * (iy)]) = 0.;
        (((double *)Y)[2 * (iy) + 1]) = 0.;
        iy += incY;
    }
}
}
