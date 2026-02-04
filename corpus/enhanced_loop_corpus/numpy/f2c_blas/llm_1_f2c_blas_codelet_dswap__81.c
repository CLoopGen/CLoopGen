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
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        for (integer unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
            dtemp = dx[i__];
            dx[i__] = dy[i__];
            dy[i__] = dtemp;
        }
    }
}
}
