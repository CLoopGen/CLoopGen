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
    float *y_ptr = (float *)Y;
    int local_iy = iy;
    for (i = 0; i < lenY; i++) {
        // Introduce artificial RAW dependency: current store depends on prior iteration via conditional update
        if (i > 0) {
            y_ptr[2 * local_iy] = y_ptr[2 * local_iy - 2] + 0.; // RAW: read previous value
            y_ptr[2 * local_iy + 1] = y_ptr[2 * local_iy - 1] + 0.;
        } else {
            y_ptr[2 * local_iy] = 0.;
            y_ptr[2 * local_iy + 1] = 0.;
        }
        local_iy += incY;
    }
    iy = local_iy; // Loop-carried dependency on index, but final write only
}
