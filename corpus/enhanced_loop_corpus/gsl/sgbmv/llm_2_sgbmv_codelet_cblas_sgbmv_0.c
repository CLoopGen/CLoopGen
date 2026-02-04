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
    // Variant 1: Consecutive memory access by removing strided indexing
    // Instead of using iy and incY, write directly to Y[0:lenY] consecutively
    for (i = 0; i < lenY; i++) {
        Y[i] = 0;
    }
}
