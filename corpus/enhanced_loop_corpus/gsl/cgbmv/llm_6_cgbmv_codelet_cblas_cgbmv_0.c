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
    int temp_iy = iy;
    for (i = 0; i < lenY; i++) {
        y_ptr[2 * temp_iy] = 0.;
        y_ptr[2 * temp_iy + 1] = 0.;
        temp_iy += incY;
    }
    iy = temp_iy; // Introduce WAW dependency: write to iy only once at end (eliminates loop-carried WAW on iy)
}
