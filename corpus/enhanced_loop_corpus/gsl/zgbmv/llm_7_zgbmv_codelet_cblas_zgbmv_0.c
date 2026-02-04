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
    double *y_ptr = (double *)Y;
    int local_iy = iy;
    for (i = 0; i < lenY; i++) {
        y_ptr[2 * local_iy] = 0.;
        y_ptr[2 * local_iy + 1] = 0.;
        local_iy += incY;
    }
    iy = local_iy; // Introduce WAW dependency with original iy update
}
