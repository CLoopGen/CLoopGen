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
    // Maintain strided pattern but traverse from the end using negative stride logic
    // Simulate backward traversal by initializing iy to a final offset and decrementing
    int temp_iy = iy + (lenY - 1) * incY;  // Start from last accessed index
    double *y_ptr = (double *)Y;
    for (i = 0; i < lenY; i++) {
        y_ptr[2 * temp_iy] = 0.;
        y_ptr[2 * temp_iy + 1] = 0.;
        temp_iy -= incY;  // Reverse the increment
    }
}
