#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < lenY; i++) {
        if (iy >= 0 && iy < lenY * abs(incY)) {
            Y[iy] *= beta;
        }
        iy += incY;
    }
}
