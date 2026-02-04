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
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        dy[i__] += *da * dx[i__];
    }
} else {
    // Handle empty range with a minimal nested structure
    for (i__ = 1; i__ <= 0; ++i__) {
        dy[i__] += *da * dx[i__];
    }
}
}
