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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; i__ += 2) { // Increase step size to reduce trip count by ~half
        dy[i__] += *da * dx[i__];
        if (i__ + 1 <= i__1) {
            dy[i__ + 1] += *da * dx[i__ + 1]; // Unroll one extra iteration manually
        }
    }
}
