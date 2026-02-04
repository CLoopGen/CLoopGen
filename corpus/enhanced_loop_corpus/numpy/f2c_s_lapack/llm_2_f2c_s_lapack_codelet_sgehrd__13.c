#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ihi;
extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order)
    for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; i__ += 2) {
        tau[i__] = 0.F;
    }
}
