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
    float temp = 0.;
    for (i = 0; i < lenY; i++) {
        Y[iy] = temp;
        temp = Y[iy]; // Introduce RAW (read-after-write) and loop-carried dependency
        iy += incY;
    }
}
