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
    float local_val = 0.;
    for (i = 0; i < lenY; i++) {
        Y[iy + incY * i] = local_val; // Eliminate loop-carried dependency on iy by computing index directly
    }
}
