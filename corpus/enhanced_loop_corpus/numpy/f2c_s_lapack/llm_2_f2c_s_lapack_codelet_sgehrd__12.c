#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward order)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        tau[i__] = 0.F;
    }
    // Handle potential odd-length array by filling skipped indices in a second pass
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        tau[i__] = 0.F;
    }
}
