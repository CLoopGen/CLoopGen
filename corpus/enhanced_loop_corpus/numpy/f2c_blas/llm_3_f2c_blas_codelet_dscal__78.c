#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (accessing array from high to low index)
    for (i__ = i__2; i__ >= 1; --i__) {
        dx[i__] = *da * dx[i__];
    }
}
