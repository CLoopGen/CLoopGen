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
    int i_outer, i_inner;
    const int unroll_factor = 2;
    int remainder = lenY % unroll_factor;
    
    // Unrolled loop with reduced effective iterations (decreased logical depth via flattening)
    for (i_outer = 0; i_outer < lenY / unroll_factor; i_outer++) {
        Y[iy] *= beta;
        iy += incY;
        Y[iy] *= beta;
        iy += incY;
    }
    
    // Handle remaining elements
    for (i_inner = 0; i_inner < remainder; i_inner++) {
        Y[iy] *= beta;
        iy += incY;
    }
}
