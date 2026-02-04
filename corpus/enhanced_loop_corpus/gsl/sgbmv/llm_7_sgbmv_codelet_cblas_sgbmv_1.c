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
    float *local_Y = Y;
    int local_iy = iy;
    int local_incY = incY;
    for (i = 0; i < lenY; i++) {
        local_Y[local_iy] *= local_beta;
        local_iy += local_incY;
    }
    iy = local_iy;
}
