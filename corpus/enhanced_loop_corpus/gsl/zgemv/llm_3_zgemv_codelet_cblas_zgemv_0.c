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
    // Variant 2: Strided access with reversed traversal
    // Start from the end and move backwards with the same stride logic
    iy = (lenY - 1) * incY;  // Initialize iy to point to last relevant segment
    for (i = 0; i < lenY; i++) {
        (((double *)Y)[2 * iy]) = 0.;
        (((double *)Y)[2 * iy + 1]) = 0.;
        iy -= incY;  // Decrement stride instead of incrementing
    }
}
