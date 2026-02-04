#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern doublereal *c__;
extern doublereal *s;
extern integer i__1;
extern integer i__;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access (process array from high to low index)
    for (i__ = i__1; i__ >= 1; --i__) {
        dtemp = *c__ * dx[i__] + *s * dy[i__];
        dy[i__] = *c__ * dy[i__] - *s * dx[i__];
        dx[i__] = dtemp;
    }
}
