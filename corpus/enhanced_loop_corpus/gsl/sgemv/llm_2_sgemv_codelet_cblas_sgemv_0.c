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
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *ptr = Y;
    for (i = 0; i < lenY; i++) {
        *ptr = 0.0f;
        ptr += incY; // Strided progression through the array
    }
}
