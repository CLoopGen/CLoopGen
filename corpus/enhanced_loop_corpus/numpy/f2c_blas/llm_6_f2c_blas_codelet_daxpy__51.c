#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_i = i__;
    for (i__ = mp1; i__ <= i__1; i__ += 4) {
        doublereal da_val = *da;
        dy[i__] += da_val * dx[i__];
        dy[i__ + 1] += da_val * dx[i__ + 1];
        dy[i__ + 2] += da_val * dx[i__ + 2];
        dy[i__ + 3] += da_val * dx[i__ + 3];
    }
    i__ = temp_i;
}
