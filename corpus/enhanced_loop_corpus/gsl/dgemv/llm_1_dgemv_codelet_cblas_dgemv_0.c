#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective depth by unrolling the loop assuming small maximum size
    // This version eliminates the loop entirely if lenY is known to be small (e.g., up to 4)
    // Using conditional expansion without additional loops

    if (lenY > 0) Y[iy] = 0., iy += incY;
    if (lenY > 1) Y[iy] = 0., iy += incY;
    if (lenY > 2) Y[iy] = 0., iy += incY;
    if (lenY > 3) Y[iy] = 0., iy += incY;

    // Handle remaining elements with a simple loop only if lenY exceeds unroll count
    for (i = 4; i < lenY; i++) {
        Y[iy] = 0.;
        iy += incY;
    }
}
