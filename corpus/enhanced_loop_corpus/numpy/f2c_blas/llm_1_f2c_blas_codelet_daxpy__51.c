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
    for (i__ = mp1; i__ <= i__1; i__ += 8) {
        for (int k = 0; k < 2 && (i__ + 4*k + 3) <= i__1; ++k) {
            dy[i__ + 4*k] += *da * dx[i__ + 4*k];
            dy[i__ + 4*k + 1] += *da * dx[i__ + 4*k + 1];
            dy[i__ + 4*k + 2] += *da * dx[i__ + 4*k + 2];
            dy[i__ + 4*k + 3] += *da * dx[i__ + 4*k + 3];
        }
    }
}
