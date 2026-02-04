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
    for (i = 0; i < lenY; i++) {
        if (i % 2 == 0) {
            Y[iy] = 0.;
        }
        iy += incY;
    }
}
