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
    // Instead of strided access via iy, rewrite to access consecutive elements in Y
    float *yPtr = (float *)Y;
    for (i = 0; i < lenY; i++) {
        int baseIndex = 2 * i;
        yPtr[baseIndex] = 0.0f;
        yPtr[baseIndex + 1] = 0.0f;
    }
}
