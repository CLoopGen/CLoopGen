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
    // Variant 2: Strided memory access with increased stride to demonstrate non-unit step pattern
    ptrdiff_t stride = 2;  // Stride factor
    for (i__ = 0; i__ <= i__1; i__ += stride) {
        iwork[iprmpt + i__] = 1;
        iwork[igivpt + i__] = 1;
    }
}
