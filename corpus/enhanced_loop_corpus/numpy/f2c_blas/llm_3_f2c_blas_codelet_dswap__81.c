#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from high to low
    for (i__ = i__1; i__ >= 1; --i__) {
        dtemp = dx[i__];
        dx[i__] = dy[i__];
        dy[i__] = dtemp;
    }
}
