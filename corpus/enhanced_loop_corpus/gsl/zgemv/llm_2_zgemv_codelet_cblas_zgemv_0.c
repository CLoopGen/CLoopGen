#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via iy, access consecutive double elements in Y
    double *yPtr = (double *)Y;
    for (i = 0; i < lenY; i++) {
        yPtr[2 * i] = 0.;
        yPtr[2 * i + 1] = 0.;
    }
}
