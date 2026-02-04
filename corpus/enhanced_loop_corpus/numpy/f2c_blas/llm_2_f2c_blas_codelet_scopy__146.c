#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    real *sx_local = sx + mp1;
    real *sy_local = sy + mp1;
    for (i__ = mp1; i__ <= i__1 - 6; i__ += 7) {
        *sy_local++ = *sx_local++;
        *sy_local++ = *sx_local++;
        *sy_local++ = *sx_local++;
        *sy_local++ = *sx_local++;
        *sy_local++ = *sx_local++;
        *sy_local++ = *sx_local++;
        *sy_local++ = *sx_local++;
    }
}
