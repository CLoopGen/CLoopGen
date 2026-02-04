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
    float local_beta = beta;
    for (i = 0; i < lenY; i++) {
        Y[iy] *= local_beta;
        iy += incY;
    }
}
