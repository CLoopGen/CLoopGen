#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (lenY > 0) {
    for (i = 0; i < lenY; i += 2) {
        Y[iy] = 0.;
        iy += incY;
        if (i + 1 < lenY) {
            Y[iy] = 0.;
            iy += incY;
        }
    }
}
}
