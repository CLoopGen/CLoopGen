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
    if (mp1 > i__1) return;
    for (i__ = mp1; i__ <= i__1; i__ += 4) {
        if (*da != 0.0) {
            dy[i__] += *da * dx[i__];
            dy[i__ + 1] += *da * dx[i__ + 1];
            dy[i__ + 2] += *da * dx[i__ + 2];
            dy[i__ + 3] += *da * dx[i__ + 3];
        }
    }
}
