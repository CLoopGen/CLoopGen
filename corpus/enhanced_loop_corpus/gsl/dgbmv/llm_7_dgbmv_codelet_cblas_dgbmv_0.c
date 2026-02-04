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
    int local_iy = iy;
    for (i = 0; i < lenY; i++) {
        Y[local_iy] = 0;             // Eliminate loop-carried dependency via local index
        local_iy += incY;            // Update local copy instead of shared state
    }
    iy = local_iy;  // Update global iy only once after loop (removes WAR/WAW on iy)
}
