#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by 2 for better spatial locality)
    integer stride = *incy;
    integer iy_temp = iy;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        // Process two elements consecutively based on current iy and next index
        y[iy_temp].r = 0.0; y[iy_temp].i = 0.0;
        iy_temp += stride;
        
        if (i__ + 1 <= i__1) {
            y[iy_temp].r = 0.0; y[iy_temp].i = 0.0;
            iy_temp += stride;
        }
    }
    iy = iy_temp; // Update global iy after loop
}
