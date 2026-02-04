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
    int i, j;
    for (i = 0; i < lenY; i++) {
        for (j = 0; j < 1; j++) {  // Increased depth: introduced a nested loop with fixed iteration
            Y[iy] = 0.;
            iy += incY;
        }
    }
}
