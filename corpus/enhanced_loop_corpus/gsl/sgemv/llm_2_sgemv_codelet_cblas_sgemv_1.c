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
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *y_ptr = Y;
    float b = beta;
    for (i = 0; i < lenY; i++) {
        *y_ptr *= b;
        y_ptr += incY;
    }
}
