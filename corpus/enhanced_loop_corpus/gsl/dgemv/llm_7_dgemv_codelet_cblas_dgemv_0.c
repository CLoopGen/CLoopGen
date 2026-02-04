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
    double local_val = 0.;
    for (i = 0; i < lenY; i++) {
        Y[iy + incY * i] = local_val;  // Eliminate WAW and WAR dependencies by writing to unique locations
        // No loop-carried dependency: each iteration writes to a distinct memory location
    }
    // Final update of iy outside the loop to preserve external state consistency
    iy += incY * lenY;
}
