#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer i__;
extern integer igivpt;
extern integer iprmpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing consecutive elements, we now access every 2nd element
    for (i__ = 0; i__ <= i__1; i__ += 2) {
        if (iprmpt + i__ < 0 || igivpt + i__ < 0) continue; // Avoid invalid indices
        iwork[iprmpt + i__] = 1;
        iwork[igivpt + i__] = 1;
    }
}
